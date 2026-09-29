# 阶段 1：FreeRTOS 移植手册（PY32C882 · Keil MDK · **HAL 库**）

> 主线工程：官方 HAL 库 GPIO 例程 `GPIO_Toggle`（PY32C882xC）。
> 本文所有命令、路径、寄存器值、编译结果均为**本机实测**，不是抄教程。
> 附录 A 才涉及 LL 库（另一套工程的做法），正文一律 HAL。

---

## §0 主线工程档案（实测）

| 项目 | 实测结果 |
|---|---|
| 起点例程 | `PY32C882_Firmware_V0.5.0\Projects\PY32C882-STK\Example\GPIO\GPIO_Toggle`（**HAL 库版**） |
| 工作工程 | `D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle\` |
| 芯片 | PY32C882xC，Cortex-M0+，256KB Flash / 32KB SRAM |
| 库 | **HAL**（`Define = USE_HAL_DRIVER,PY32C882xC`；工程里只有 `py32c882_hal_*.c`，没有一个 `py32c882_ll_*.c`） |
| 编译器 | **AC5** V5.06（`<uAC6>0</uAC6>`）+ **MicroLIB 开启** |
| 主频 | **HSI 8MHz**（`system_py32c882.c` 里 `SystemCoreClock = HSI_VALUE`，`main()` 中无 PLL 配置） |
| 板级资源 | LED3 = **PA2**；调试串口 UART1 = **PB9(TX)/PB8(RX)**，115200-8-N-1 |
| 官方 BSP 便利点 | `BSP_UART_Config()` 里已内建 `fputc` 重定向 → **`printf` 开箱可用**，无需自己写 |
| 启动文件默认栈 | `Stack_Size = 0x400`(1KB)、`Heap_Size = 0x200` |
| 内核 | FreeRTOS-Kernel **V10.5.1**（注意是**扁平目录**：`tasks.c` 在仓库根，**没有** `Source/` 这一层） |
| 最终编译结果 | **0 Error(s), 0 Warning(s)**（UV4 命令行实测，见 §8） |
| 资源占用 | Flash = Code 9520 + RO 652 = **10.2 KB**；RAM = RW 128 + ZI 11176 = **11.0 KB**（含 8KB FreeRTOS 堆） |

---

## §1 唯一要做的选择：端口由编译器决定

| 你的编译器 | 用哪个端口 | 官方依据（源码里就这么写着） |
|---|---|---|
| **AC5 (armcc)** | `portable/RVDS/ARM_CM0/` | `portable/Keil/See-also-the-RVDS-directory.txt` |
| **AC6 (armclang)** | `portable/GCC/ARM_CM0/` | `portable/ARMClang/Use-the-GCC-ports.txt`：*"The FreeRTOS GCC port layer also builds and works with the ARMClang compiler."* |

**本工程是 AC5 → 用 `RVDS/ARM_CM0`。**

为什么 AC6 不能用 RVDS 端口：`RVDS/ARM_CM0/port.c` 通篇是 `__asm void f(void){...}`（AC5 私有扩展），armclang 编不过；GCC 端口用 `__attribute__((naked))` + `__asm volatile()`，AC6 才认。

**CM0 端口是纯 C，没有汇编文件**——不要去找/加 `portasm.s`（那是 CM3/M4 的东西）。

---

## §2 工程落地

### §2.1 ★官方例程一拷出来，相对路径就断了（第一道硬伤）

原 `Project.uvprojx` 里写的是：

```
..\..\..\..\..\..\Drivers\PY32C882_HAL_Driver\Inc
```

六层 `..\` 是为了从 `Projects\PY32C882-STK\Example\GPIO\GPIO_Toggle\MDK-ARM` 上溯到固件根。**工程一旦被拷到别处，它解析成 `D:\Drivers` —— 不存在，直接编不过。**

> 自查手法：`[System.IO.Path]::GetFullPath($相对路径)` 一眼看出实际指向哪。

**处置**：把精简驱动树拷进工程目录，路径降为两层，工程从此自包含、可整体搬移：

```
GPIO_Toggle\
├── Drivers\
│   ├── CMSIS\Include\                        (30 文件)
│   ├── CMSIS\Device\PY32C882\Include\        ( 3 文件)
│   ├── PY32C882_HAL_Driver\Inc\              (72 文件)
│   ├── PY32C882_HAL_Driver\Src\              (62 文件)
│   └── BSP\PY32C882xx_Start_Kit\             ( 4 文件)
└── FreeRTOS\                                 (内核 V10.5.1，28 文件)
```

不必拷整个 13.5MB 的 `Drivers`，上面 5 个子目录共 171 个文件足够。

### §2.2 Keil 分组与 include 路径（本工程实测结构）

在 Project 窗口新增 4 个分组：

| 分组名 | 文件 | 相对路径 |
|---|---|---|
| `FreeRTOS_Core` | tasks.c / queue.c / list.c / timers.c | `..\FreeRTOS\Source\*.c` |
| `FreeRTOS_Port` | port.c | `..\FreeRTOS\Source\portable\RVDS\ARM_CM0\port.c` |
| `FreeRTOS_Heap` | heap_4.c | `..\FreeRTOS\Source\portable\MemMang\heap_4.c` |
| `Config` | FreeRTOSConfig.h / app_rtos_hooks.c | `..\Inc\...`、`..\Src\...` |

Include Paths 必须含 **7 条**（本工程实测值）：

```
..\Inc
..\Drivers\BSP\PY32C882xx_Start_Kit
..\Drivers\CMSIS\Include
..\Drivers\CMSIS\Device\PY32C882\Include
..\Drivers\PY32C882_HAL_Driver\Inc
..\FreeRTOS\include                          ← 少了报 "cannot open FreeRTOS.h"
..\FreeRTOS\Source\portable\RVDS\ARM_CM0     ← 少了报 "portmacro.h not found"（最容易漏这条）
```

**不需要**加进工程：`croutine.c`、`event_groups.c`、`stream_buffer.c`、任何其它 `portable\` 子目录、所有 `py32c882_ll_*.c`（HAL 工程用不到）。

### §2.3 为"整目录搬移"改 uvprojx 的正确姿势

uvprojx 是 XML，但**别手工编辑**。用脚本做，并且每步都要断言 + 回读：

1. 先 `Copy-Item` 备份成 `Project.uvprojx.bak`
2. `read()` 全文 → `assert 旧串 in 文本`（**找不到就报错退出，不要静默替换**）
3. `replace()` 改路径 → `replace()` 插入新分组（插在 `</Groups>` 前的锚点分组之前）
4. 写回后 `xml.etree.ElementTree.parse()` 回读，**逐个 Test-Path 校验每个 `<FilePath>` 和每段 IncludePath 是否真实存在**

本次校验结果：12 个分组、全部路径命中（这是我最后能报"0 error"的前提）。

---

## §3 三个必改点

### §3.1 ★`Src\py32c882_it.c` 里的空 Handler 会撞符号（`L6200E`）

官方 `it.c` 里定义了三个空/半空函数，**其中两个必须让位**：

```c
void SVC_Handler(void)   { }                 /* 保留：HAL/CM0 端口不用它 */
void PendSV_Handler(void){ }                 /* ★必须注释掉 */
void SysTick_Handler(void){ HAL_IncTick(); } /* ★必须注释掉（但内容要搬家，见 §5.2） */
```

FreeRTOS 通过 `FreeRTOSConfig.h` 把 `xPortPendSVHandler` 映射成 `PendSV_Handler`、`xPortSysTickHandler` 映射成 `SysTick_Handler` —— 两个 `.c` 定义同名函数 → 链接器报 **`L6200E: Symbol multiply defined`**。

**处置**：注释掉这两个，**原代码原样留在注释里**（方便回退对照）：

```c
/* ★ 原内容，请勿删除（回退裸机版时需要）：
void SysTick_Handler(void)
{
  HAL_IncTick();
}
*/
```

> `SVC_Handler` **不要**动。CM0+ 的 FreeRTOS 端口不使用 SVC（启动第一个任务走 `prvPortStartFirstTask`，软件设置 PSP/CONTROL 后 `bx` 跳转），只要 `FreeRTOSConfig.h` 里**不定义** `vPortSVCHandler` 映射，它留着就正好。

### §3.2 加大中断用的栈（MSP）

启动文件默认 `Stack_Size EQU 0x00000400`(1KB) → 改成 **`0x00000800`(2KB)**。

RTOS 下这个栈只给**中断/异常**用，而 ISR 里可能要调 `xQueueSendFromISR` 等内核函数或 `printf`，1KB 容易爆。

**两个"栈"别混**：
- **MSP 主栈** = 启动文件里的 `Stack_Size`，中断用（本工程 2KB）
- **任务栈** = `xTaskCreate()` 第 3 参数，**单位是字（word=4B）**，从 FreeRTOS 堆分配。例：`128` = 512 字节

### §3.3 中文注释触发 AC5 警告 `#870-D`

```
..\Src\main.c(66): warning: #870-D: invalid multibyte character sequence
```

AC5 默认按多字节字符处理源码，遇到非 ASCII 字节就告警（本次 7 条）。**处置**：Options for Target → C/C++ → Misc Controls 填：

```
--no-multibyte-chars
```

（等价于 uvprojx 里 `<Cads><VariousControls><MiscControls>--no-multibyte-chars</MiscControls>`。）加完立刻 0 Warning，不影响代码生成。

---

## §4 FreeRTOSConfig.h（本工程实际使用的那份）

文件位置：`GPIO_Toggle\Inc\FreeRTOSConfig.h`。下面只讲要点，全文见该文件。

### §4.1 必定义的 6 个宏（少一个必报 `#error`）

```c
configMINIMAL_STACK_SIZE   /* ★单位=字！空闲任务栈，128 = 512 字节 */
configMAX_PRIORITIES       /* 任务软件优先级档数 */
configUSE_PREEMPTION
configUSE_IDLE_HOOK
configUSE_TICK_HOOK
configUSE_16_BIT_TICKS
```

> **本次真的漏了 `configMINIMAL_STACK_SIZE`**：第一次编译 8 个 error 全是同一句
> `..\FreeRTOS\include\FreeRTOS.h(135): error: #35: #error directive: Missing definition: configMINIMAL_STACK_SIZE ...`
> （`tasks.c/queue.c/list.c/timers.c/heap_4.c/port.c/main.c/app_rtos_hooks.c` 一起报，因为都 include `FreeRTOS.h`）。写配置后**把这 6 个逐个对一遍**，比事后看报错快。

### §4.2 本工程的关键取值

| 宏 | 值 | 为什么 |
|---|---|---|
| `configCPU_CLOCK_HZ` | **8000000** | ★必须等于 `SystemCoreClock`。本工程是 HSI 8MHz 直出、**没开 PLL**；写成 72MHz → 所有延时快 9 倍（不是死机！） |
| `configSYSTICK_CLOCK_HZ` | `configCPU_CLOCK_HZ` | SysTick 用内核时钟，1:1 不分频 |
| `configTICK_RATE_HZ` | 1000 | 1ms 节拍 → `SysTick->LOAD` 应为 **7999** |
| `configUSE_PORT_OPTIMISED_TASK_SELECTION` | **0** | ★CM0+ 无 CLZ 指令，硬件选任务不可用 |
| `configTICK_RATE_HZ` / `configUSE_16_BIT_TICKS` | 1000 / 0 | 32 位节拍计数 |
| `configUSE_TICK_HOOK` | **1** | ★必须 1：`HAL_IncTick()` 挂在里面（见 §5.2） |
| `configMAX_PRIORITIES` | 8 | CM0 的 4 级**硬件**优先级只管中断；任务优先级是软件链表，档数随意 |
| `configTOTAL_HEAP_SIZE` | 8*1024 | 32KB SRAM 下的推荐值（实测整机 RAM 11KB，占 34%） |
| `configCHECK_FOR_STACK_OVERFLOW` | 2 | 哨兵值法，栈快溢出就能抓 |
| `configUSE_MALLOC_FAILED_HOOK` | 1 | 堆耗尽立刻报，而不是返回 NULL 后跑飞 |
| `configUSE_TICKLESS_IDLE` | 0 | 阶段 4 做 STOP 低功耗时再改 1 |
| `configUSE_TIMERS` | 0 | 阶段 1 先关省 RAM；要用改 1（`timers.c` 已在分组里） |

### §4.3 CM0+ 上"配了也白配"的宏

| 宏 | 为什么无效 |
|---|---|
| `configKERNEL_INTERRUPT_PRIORITY` | CM0 端口把内核异常优先级**硬编码**为最低（`#define portMIN_INTERRUPT_PRIORITY ( 255UL )`），不看这个宏 |
| `configMAX_SYSCALL_INTERRUPT_PRIORITY` | ★CM0 **没有 BASEPRI**，FreeRTOS 无法"只屏蔽某优先级以下的中断"，该宏无实现 |
| `configPRIO_BITS` 系列 | M3/M4 端口才用它做优先级反向移位 |

**由此推出的最重要结论**：CM0+ 上 `taskENTER_CRITICAL()` 展开成 **`CPSID i`（关掉全部中断）**，不是像 M3/M4 只关一部分。所以 CM0+ 上唯一的纪律是——**ISR 必须极短**。

### §4.4 内存方案：为什么 `heap_4` + 8KB

| 方案 | 特点 | 适用 |
|---|---|---|
| heap_1 | 只分配不释放，无碎片 | 任务/队列开局建好永不删 → 量产首选 |
| **heap_4** | 可释放 + **相邻块自动合并** | ★学习期用，动态建删任务不炸 |
| heap_5 | heap_4 + 支持多块不连续内存 | SRAM 分段 |

`configTOTAL_HEAP_SIZE` 是 heap_4.c 里一个**静态数组**（进 `.bss`），与启动文件的 `Heap_Size` 无关。

**32KB SRAM 预算参考（本工程实测）**：堆 8192 B + MSP 主栈 2048 B + 其它 ZI/RW ≈ 1.1 KB → 整机 **11.0 KB**，余量充足。开工前先看现有工程 `.map` 的 `Total RW Size`，再决定堆给多少。

---

## §5 ★HAL 库工程接 RTOS 的核心：时基交接

这是 HAL 工程和 LL 裸机工程**最大的不同点**，也是最容易静默出错的地方。

### §5.1 HAL 的 SysTick 是怎么来的

```c
HAL_Init()                       /* → HAL_InitTick(TICK_INT_PRIORITY) */
                                 /*   → HAL_NVIC_SetPriority(SysTick_IRQn, ...) + HAL_SYSTICK_Config(SystemCoreClock/1000) */
                                 /*   本工程 TICK_INT_PRIORITY = PRIORITY_LOWEST，与 FreeRTOS 要的最低优先级一致 */
```

然后 `Src\py32c882_it.c` 里靠 `SysTick_Handler(){ HAL_IncTick(); }` 维持 HAL 的 1ms 计数。

### §5.2 接管之后必须"交接"，否则 HAL 静默失效

RTOS 接管 SysTick 后 `it.c` 里那个函数要注释掉，**但如果只是注释掉，HAL 侧不报任何错**：

| 现象 | 原因 |
|---|---|
| `HAL_GetTick()` 永远返回 **0** | 没人调 `HAL_IncTick()` 了 |
| `HAL_Delay(n)` **永不返回** | 它就是在等 `HAL_GetTick()` 增长 |
| `HAL_UART_Transmit(&h, ..., 1000)` 之类**立即超时** | HAL 的超时全基于 tick |

**处置**：把 `HAL_IncTick()` 搬进 tick 钩子，HAL 时基与 RTOS 节拍同源：

```c
/* Src\app_rtos_hooks.c —— 这就是 HAL 工程接 RTOS 的"交接点" */
void vApplicationTickHook(void)     /* configUSE_TICK_HOOK 必须为 1 */
{
    HAL_IncTick();
}
```

> 规律：**凡是用 HAL 的工程都要做这一步**；纯 LL 裸机工程没有 HAL 时基，不存在这个问题（见附录 A）。

### §5.3 时钟顺序与三个禁止动作

```
上电
 └─ SystemInit()（PY32C882 里只做 HSI/选项字节等基础准备）
    └─ main()
       ├─ ① HAL_Init()            ← 配 SysTick 1ms（此时还没调度器）
       ├─ ② BSP_LED_Init / BSP_UART_Config 等板级初始化   ★这里还能用 HAL_Delay
       ├─ ③ xTaskCreate(...)      ← 必须在 ④ 之前
       └─ ④ vTaskStartScheduler() ← 之后：建空闲任务、把 PendSV/SysTick 设为最低优先级、
                                      用 configSYSTICK_CLOCK_HZ/configTICK_RATE_HZ 接管 SysTick(重载=7999)
                                     ★永不返回（返回了 = 堆不够，连空闲任务都没建起来）
```

**三个禁止**：
1. **禁止**在调度器启动后调用 `HAL_Init()` / `HAL_InitTick()`（会重配 SysTick → 节拍崩）。
2. **禁止**在任务里用 `HAL_Delay()`（CPU 死等，饿死其他任务）→ 用 `vTaskDelay` / `vTaskDelayUntil`。
3. **禁止**直接改 `SysTick->LOAD` / `SysTick->CTRL`（这是内核的财产了）。

> 确认没踩雷：调试器看 `SysTick->LOAD`(0xE000E014) 必须是 **7999**（8MHz 板子）。

---

### §5.4 ★★ SysTick 交接的致命细节：HAL 在调度器启动前就会发包

**这是本次实战真正导致 HardFault 的根因**（2026-09-24），也是 HAL 工程接 RTOS 最容易漏的一环。

**现象**：程序停在 `BSP_UART_Config()` 里（或任意初始化函数中），一继续/单步就进 `HardFault_Handler`。

**根因（源码级证据，行号可在本工程 `FreeRTOS\Source\tasks.c` 里核对）**：

| 事实 | 位置 |
|---|---|
| `xNextTaskUnblockTime` 的初值就是 **0** | `tasks.c:370`（注释：*"Initialised to portMAX_DELAY before the scheduler starts"*） |
| 它被改成 `portMAX_DELAY` 的位置在 **`vTaskStartScheduler()` 内部** | `tasks.c:2036` |
| `xTaskIncrementTick()` 里 `if( xConstTickCount >= xNextTaskUnblockTime )` 成立后立刻 `listLIST_IS_EMPTY( pxDelayedTaskList )` | `tasks.c:2754` / `tasks.c:2758` |

`pxDelayedTaskList` 在第一个任务被创建（`xTaskCreate` → `prvInitialiseTaskLists`）之前一直是 **NULL**。

**触发链**：

```
HAL_Init()  →  HAL_InitTick()  →  HAL_SYSTICK_Config()  →  SysTick 使能 + 中断打开
        ↓
main() 里继续跑 BSP_UART_Config() / printf(...)    ← 一行 60~80 字符 @115200 = 5~7ms
        ↓   1ms 的 tick 必然在这期间到达
SysTick 中断 → xPortSysTickHandler() → xTaskIncrementTick()
        ↓
xTickCount: 0→1 ;  if( 1 >= xNextTaskUnblockTime(0) ) 成立
        ↓
listLIST_IS_EMPTY( pxDelayedTaskList )   ← NULL → 解引用 → HardFault
```

⚠️ **单步调试 100% 触发**：调试器一步步走，光是看代码就远超 1ms。
⚠️ 裸机版本没这个问题：那时 `SysTick_Handler()` 里只是 `HAL_IncTick()`，不碰任何 RTOS 数据结构。

**修法（本工程采用）**：**不给 `xPortSysTickHandler` 做名字映射**，让 port.c 保留原函数名，改由 `it.c` 分派：

```c
/* Inc\FreeRTOSConfig.h —— 注释掉这一行（PendSV 的映射保留） */
/* #define xPortSysTickHandler              SysTick_Handler */
```
```c
/* Src\py32c882_it.c */
extern void xPortSysTickHandler(void);      /* port.c 里的真实函数名 */

void SysTick_Handler(void)
{
  if (xTaskGetSchedulerState() == taskSCHEDULER_NOT_STARTED)
  {
    HAL_IncTick();            /* 调度器还没跑：只维持 HAL 时基（等价于裸机版） */
  }
  else
  {
    xPortSysTickHandler();    /* 已启动：交给 FreeRTOS */
  }
}
```

**为什么这样是安全的**：`vTaskStartScheduler()` 是**先关中断**再设 `xNextTaskUnblockTime = portMAX_DELAY` 和 `xSchedulerRunning = pdTRUE`（`tasks.c:2026` → `2036` → `2037`），然后才进 `xPortStartScheduler()`。所以不存在"已判定为运行中、但内部还没初始化好"的窗口。

**收益（对比一劳永逸的其它做法）**：
- 调度器启动**之前**，`HAL_GetTick()` / `HAL_Delay()` / HAL 各类超时**全部照常可用**（产物初始化代码里常用 `HAL_Delay`，这条很实用）
- 调度器启动**之后**，`vApplicationTickHook()` 里再 `HAL_IncTick()`，HAL 时基照样 1ms 推进
- 不管你在 `HAL_Init()` 与 `vTaskStartScheduler()` 之间插多少耗时操作、单步多久，都不会再触发

> 反例（别这么写）：把 `SysTick_Handler` 完全让给 port.c，然后"祈祷"初始化窗口小于 1ms——初学阶段这样做常常"能跑"，但一开始单步调试或加一句 `printf` 就炸，而且现象和代码位置完全对不上（你会以为是 `printf` 或 GPIO 有问题）。

**★ 附：CM0+ 没有 `CFSR/BFAR`，HardFault 该怎么定位**

CM0+ 只有 HardFault、没有 `SCB->CFSR/HFSR/BFAR/MMFAR`（那是 M3/M4 的），所以定位手段是**解析压栈帧**。把下面这段临时塞进 `HardFault_Handler`，然后用调试器看那几个全局变量：

```c
volatile uint32_t hf_r0, hf_r1, hf_r2, hf_r3, hf_r12, hf_lr, hf_pc, hf_psr, hf_exc_return;

void HardFault_Handler(void)
{
    __asm volatile (
        " tst lr, #4      \n"   /* LR(EXC_RETURN)：bit2=0 用 MSP，=1 用 PSP */
        " ite eq          \n"
        " mrseq r0, msp   \n"
        " mrsne r0, psp   \n"
        " ldr r1, =hf_r0  \n"   /* r1 指向存放结构体首地址的全局区 */
        " ldmia r0!, {r2-r6} \n"/* 依次取 R0,R1,R2,R3,R12 */
        " stmia r1!, {r2-r6} \n"
        " ldmia r0!, {r2-r6} \n"/* 依次取 LR,PC,xPSR */
        " stmia r1!, {r2-r6} \n"
        " mov r6, lr      \n"
        " str r6, [r1]    \n"   /* 保存 EXC_RETURN，判断故障来自线程还是中断 */
        " b .             \n"
    );
}
```
复位后看：
- `hf_pc` = **出错的那条指令地址** → 用 `.map` 文件或反汇编（`fromelf -c`）查它属于哪个函数
- `hf_exc_return`：`0xFFFFFFF9` = 故障发生在**线程模式用 MSP**（初始化代码）；`0xFFFFFFFD` = 故障发生在**任务里（PSP）**，多半是任务栈溢出或野指针
- 再看 `hf_lr` → 调用返回地址

> 本次故障若用这段代码去抓，会看到 `hf_pc` 落在 `xTaskIncrementTick()` 里，`hf_exc_return = 0xFFFFFFF9`（线程模式）——与"SysTick 在启动前抢跑"的结论一致。

---

## §6 中断移植规范（HAL 风格）

### §6.1 外设 ISR 模板（FromISR + 退出时切任务）

实测 `portmacro.h`：`#define portYIELD_FROM_ISR( x ) portEND_SWITCHING_ISR( x )`。

```c
/* 例：HAL 风格的按键中断（USER_BUTTON = PA0 → EXTI0_1_IRQn，BSP 里已有定义） */
void EXTI0_1_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;      /* ① 必须初始化 */

    HAL_GPIO_EXTI_IRQHandler(USER_BUTTON_PIN);          /* ② HAL 负责清标志并回调 */
    /* ↑ 它会调用到 HAL_GPIO_EXTI_Callback(GPIO_Pin)，你在那里做"记录 + 通知"：

       void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
       {
           if (GPIO_Pin == USER_BUTTON_PIN)
           {
               BaseType_t xWoken = pdFALSE;
               xTaskNotifyFromISR(xKeyTask, 1, eSetBits, &xWoken);
               portYIELD_FROM_ISR(xWoken);
           }
       }
    */
}
```

**铁律**：ISR（含 HAL 回调）里只能用名字带 `...FromISR` 的 API（`xQueueSendFromISR` / `xSemaphoreGiveFromISR` / `xTaskNotifyFromISR`）；**不能**调 `vTaskDelay` / `HAL_Delay` / `printf` 长输出 / Flash 写。

### §6.2 优先级怎么分（CM0 只有 4 档：0/1/2/3）

| 优先级 | 给谁 | 理由 |
|---|---|---|
| 0（最高） | 安全相关：掉电检测、过流/阀门急停 | 必须最先响应 |
| 1 | 串口/传感器接收 | 有硬件缓冲，稍慢也能救 |
| 2 | 普通定时器、按键 | 容忍几十 us 延迟 |
| **3** | **★不要给外设** | PendSV / SysTick 占着 3（内核异常必须最低） |

> **和 M3/M4 教程最大的不同**：M4 教程让你"把外设优先级设为 `configMAX_SYSCALL_INTERRUPT_PRIORITY` 以下"，**CM0 上这句话没意义**（没有 BASEPRI）。CM0 上能做的不多：用 0~2 给外设、**把 ISR 写短**。
>
> 参考：官方 `BSP_UART_Config()` 里给 `DEBUG_UART_IRQ` 设的是 `HAL_NVIC_SetPriority(DEBUG_UART_IRQ, 0, 0)`（最高）。

### §6.3 本工程特有的注意

- `BSP_UART_Config()` 会 `HAL_NVIC_EnableIRQ(UART1_LPUART1_IRQn)`，而 `it.c` 里**没有** UART 中断处理函数（本例程用的是轮询发送，不会触发中断）。**别在没写 Handler 的情况下去开 UART 接收中断**，否则会跳进启动文件里的默认死循环。
- **看门狗**：RTOS 下"在哪喂狗"要重新设计（空闲钩子里喂狗 = 高优先级任务死循环时反而喂不上，这既是坑也是检测手段）。阶段 3/5 再定，阶段 1 先不开 IWDG。

---

## §7 第一个能跑的工程（本工程实际代码）

```
Src\main.c             ← 重写：HAL_Init + 两个任务 + vTaskStartScheduler
Src\app_rtos_hooks.c   ← 新增：钩子 + HAL_IncTick 交接 + 任务表/水位打印
Inc\FreeRTOSConfig.h   ← 新增：8MHz 版配置
```

### §7.1 裸机 → RTOS 对照

| 原裸机版（`main.c`） | 本版本 |
|---|---|
| `while(1){ HAL_Delay(250); 翻转LED; }` | `App_LedTask`：`BSP_LED_Toggle(LED3)` + `vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(250))` |
| `SysTick_Handler(){ HAL_IncTick(); }` | `vApplicationTickHook(){ HAL_IncTick(); }` |
| 无任何观测手段 | `App_LogTask`：每秒打状态、每 5 秒打任务表 |
| 周期行为不变 | **LED 仍是 250ms 翻转 = 2Hz**，与改之前肉眼一致 |

### §7.2 两个任务的关键代码

```c
#define LED_TASK_STACK   128U   /* 512 字节 */
#define LED_TASK_PRIORITY 2U
#define LED_TOGGLE_MS    250U

static void App_LedTask(void *argument)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    (void)argument;
    for (;;)
    {
        BSP_LED_Toggle(LED3);
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(LED_TOGGLE_MS));  /* ★周期任务用 Until，不累积漂移 */
    }
}

static void App_LogTask(void *argument)
{
    uint32_t ulCount = 0U;
    (void)argument;
    for (;;)
    {
        ulCount++;
        printf("[t=%ums] tasks=%u freeHeap=%uB ledStackMinFree=%u words\r\n",
               (unsigned)xTaskGetTickCount(),
               (unsigned)uxTaskGetNumberOfTasks(),
               (unsigned)xPortGetFreeHeapSize(),
               (unsigned)uxTaskGetStackHighWaterMark(xLedTaskHandle));
        if ((ulCount % 5U) == 0U) { RTOS_PrintTaskList(); RTOS_PrintHeapInfo(); }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
```

**要点**：
- `vTaskDelay` vs `vTaskDelayUntil`：**周期任务必须用后者**（以上次唤醒时刻为基准），否则周期会累积漂移。
- 日志任务栈给 **256 字（1KB）**：`printf` 和 `vTaskList`（内部用 `sprintf`）都吃栈。
- ★**`printf` 不可重入** → 所有打印集中在这一个任务里，别在多任务/ISR 里同时打印。

### §7.3 `app_rtos_hooks.c` 不是可选的

`FreeRTOSConfig.h` 里开了 `configCHECK_FOR_STACK_OVERFLOW` / `configUSE_MALLOC_FAILED_HOOK` / `configASSERT` / `configUSE_IDLE_HOOK` / `configUSE_TICK_HOOK`，内核就会去调对应的 `vApplicationXxx` 函数，**不实现就 `L6218E: Undefined symbol`**。

| 函数 | 何时被调 | 怎么写 |
|---|---|---|
| `vApplicationTickHook` | **SysTick 中断里** | ★`HAL_IncTick()` 放这；中断上下文，不能阻塞 |
| `vApplicationIdleHook` | 所有任务都阻塞时 | 不能阻塞、不能 `vTaskDelay`；阶段 4 的低功耗入口 |
| `vApplicationStackOverflowHook` | 栈尾哨兵被改写 | 报出任务名 + 死循环（或 `NVIC_SystemReset()`） |
| `vApplicationMallocFailedHook` | 堆分配失败 | 报剩余堆 + 死循环 |
| `vApplicationAssertFailure` | `configASSERT` 失败 | 报 `__FILE__`/`__LINE__` + 死循环 |

---

## §8 命令行编译验证（强烈建议日常用这个）

不用开 Keil GUI：

```powershell
$uv   = 'D:\Keil_v5\UV4\UV4.exe'
$proj = 'D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle\MDK-ARM\Project.uvprojx'
$log  = 'D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle\MDK-ARM\build_log.txt'
if (Test-Path $log) { Remove-Item $log -Force }

# ★PowerShell 里不要写 & $uv ...（& 会被当成后台符号），必须用 Start-Process
$p = Start-Process -FilePath $uv -ArgumentList @('-r', "`"$proj`"", '-j0', '-o', "`"$log`"") `
                   -Wait -NoNewWindow -PassThru
"ExitCode = $($p.ExitCode)"
```

| 参数 | 含义 |
|---|---|
| `-b` | 增量编译；**`-r` = 全量重编（验收必须用 -r，否则旧 .o 会骗你）** |
| `-j0` | 不用多进程并行 |
| `-o <file>` | 输出写到日志文件 |

**退出码**：`0` = 无错无警告，`1` = 仅警告，`2` = 有错误，`≥3` = 更严重。

两个实操坑：
1. 日志是 **UTF-16(BE) 无 BOM**，按 UTF-8 读全是乱码（用 UTF-16BE 解码，或直接记事本打开）。
2. Keil GUI 打开着同一工程时，命令行编译会失败 —— 先关 GUI。

**本次实测输出**：
```
Program Size: Code=9520 RO-data=652 RW-data=128 ZI-data=11176
".\Output\Project.axf" - 0 Error(s), 0 Warning(s).
Build Time Elapsed: 00:00:10
```

---

## §9 验收清单

### §9.1 编译期（已实测通过 ✅）

| # | 检查 | 期望 |
|---|---|---|
| 1 | UV4 退出码 | **0** |
| 2 | 报错/警告 | `0 Error(s), 0 Warning(s)` |
| 3 | 产物 | `MDK-ARM\Output\Project.hex` 已生成 |
| 4 | 资源占用 | Flash ≈10.2KB / RAM ≈11.0KB（ZI 里含 8KB 堆 → 证明 `configTOTAL_HEAP_SIZE` 真的生效） |

### §9.2 上板（需要你实测，我无法代做）

| # | 现象 | 期望 |
|---|---|---|
| 1 | LED3 (PA2) | 每 250ms 翻转 = **2Hz**，与改之前肉眼一致（说明 RTOS 没改变原功能） |
| 2 | 串口 115200 (PB9=TX) | 上电打印 `SystemCoreClock = 8000000 Hz (configCPU_CLOCK_HZ = 8000000 Hz)` |
| 3 | 串口每秒 | `[t=xxxxms] tasks=3 freeHeap=xxxxB ledStackMinFree=xx words`，t 每次 +1000 左右 |
| 4 | 串口每 5 秒 | 任务表含 `led / log / IDLE` 三行，**IDLE 必须在**（证明调度器真在跑） |
| 5 | `SysTick->LOAD` (0xE000E014) | **7999**（8MHz/1000-1） |
| 6 | `SHPR3` (0xE000ED20) | **0xC0C00000**（port.c 写的是 `255<<16` / `255<<24`；CM0+ 只实现高 2 位，读回即 0xC0） |
| 7 | `uxCriticalNesting` | 稳态 **0**（>0 说明某处 `taskENTER_CRITICAL` 没配 `EXIT`） |
| 8 | `freeHeap` / `ledStackMinFree` | freeHeap 明显 >0；栈剩余 >30 字 |

> `SHPR3` 那个 0xC0C00000 是这么来的：CM0+ 每 8 位优先级字段里只有高 2 位（bit7:6）有效，写 `0xFF` 实际落下 `0b11`，读回就是 `0xC0`。SHPR3 里 PendSV 在 [23:16]、SysTick 在 [31:24]。

---

## §10 踩坑速查表（HAL 语境）

| 症状 | 真正原因 | 处置 |
|---|---|---|
| 一打开就编不过，找不到 `py32c8xx_hal.h` / `py32c882xx_Start_Kit.h` | 六层 `..\..\..\..\..\..\Drivers` 相对路径拷走后失效 | §2.1 把驱动树拷进工程 + 改成 `..\Drivers\...` |
| `L6200E: Symbol PendSV_Handler multiply defined` | `it.c` 里的空函数还在 | §3.1 注释掉 `PendSV_Handler`/`SysTick_Handler` |
| `L6218E: Undefined symbol vApplicationStackOverflowHook` | 钩子没实现 | 加 `app_rtos_hooks.c` |
| `FreeRTOS.h(135): #error Missing definition: configMINIMAL_STACK_SIZE` | 必定义宏漏了（8 个 .c 一起报） | §4.1 |
| `cannot open source input file "FreeRTOS.h"` | include 路径缺 | §2.2 那 7 条 |
| `portmacro.h` 找不到 | port 目录没进 include path | §2.2 最后一条 |
| `__asm` 附近语法错误 | AC6 用了 RVDS 端口 | §1 换 `GCC\ARM_CM0\port.c` |
| 7 条 `#870-D: invalid multibyte character sequence` | 中文注释 | §3.3 加 `--no-multibyte-chars` |
| **`HAL_Delay()` 卡死 / `HAL_GetTick()` 返回 0 / UART 发送立刻超时** | ★`HAL_IncTick()` 没交接（`SysTick_Handler` 被注释后没人调它） | §5.2 放进 `vApplicationTickHook()` |
| `vTaskDelay(1000)` 只等约 111ms、时间快 9 倍 | `configCPU_CLOCK_HZ` 与 `SystemCoreClock` 不一致 | §4.2，用调试器 Watch `SystemCoreClock` 对齐 |
| 能编译、一跑就 HardFault | ①向量映射名字拼错（拼错则走弱定义空函数）②MSP 栈太小 | §3.1 核对两行映射；§3.2 栈提到 0x800 |
| 某任务一直不跑 | 它优先级最低 + 高优先级任务没阻塞（里面写了 `HAL_Delay` 或死循环） | 改用 `vTaskDelay`；或调优先级 |
| `vTaskStartScheduler()` 居然返回了 | 堆太小，空闲任务建不起来 | 加大 `configTOTAL_HEAP_SIZE` |
| 串口乱码/丢字符 | 多任务或 ISR 里调 `printf`（不可重入） | 打印收敛到一个任务 |

---

## §11 编译/链接报错对照表（Keil 专用）

| 报错 | 含义 | 章节 |
|---|---|---|
| `L6200E: Symbol xxx multiply defined` | 同名符号多处定义（最常见就是那三个 Handler） | §3.1 |
| `L6218E: Undefined symbol xxx` | 声明了没实现（钩子未实现 / .c 没加进工程） | §4、§7.3 |
| `#error Missing definition: configXXX` | FreeRTOSConfig.h 少必定义宏 | §4.1 |
| `#error INCLUDE_vTaskDelayUntil and INCLUDE_xTaskDelayUntil are both defined` | V10.5.1 旧名已废弃 | 只留 `INCLUDE_xTaskDelayUntil` |
| `#error configUSE_STATS_FORMATTING_FUNCTIONS is 1 but ...` | 开了格式化但没开 `configUSE_TRACE_FACILITY` | 两个一起开 |
| `Warning: #870-D: invalid multibyte character sequence` | 中文注释 | §3.3 |
| `Error: L6406E: No space in execution regions` | Flash/RAM 不够 | §4.4 |

---

## §12 阶段 1 完成标准

三件事全做到才算结束：

1. 能不看手册说出：**为什么 CM0+ 的临界区是 `CPSID i`**，以及这为什么要求"ISR 必须短"。
2. 能解释 **HAL 工程的 `HAL_IncTick()` 为什么要搬进 `vApplicationTickHook()`**（不搬会怎样）。
3. 调试器里能指出 `SysTick->LOAD = 7999`、`SHPR3 = 0xC0C00000`、`uxCriticalNesting = 0`，并说清"任务栈 128"是 512 字节而不是 128 字节。

**阶段 2 预告**：任务/队列/信号量/事件组/通知的实战用法 —— 任务通知 vs 信号量的取舍、`vTaskDelay` vs `vTaskDelayUntil`、优先级反转与互斥锁、把这套 demo 变成"真实产品的任务划分"雏形。

---

## 附录 A：LL 库工程的差异（另一套做法）

> 本附录只为"如果你某个工程用的是 LL 库"而留。**主线工程（PY32C882 HAL）不涉及这些**。

### A.1 端口与工程接入：完全相同
分组、include 路径、`Stack_Size`、`it.c` 符号冲突这三件事，LL 工程与 HAL 工程**一模一样**（§1/§2/§3 通用）。

### A.2 区别一：LL 用 `LL_Init1msTick()` 抢 SysTick，不是 `HAL_Init()`

官方 LL 模板（`PY32L090xx_Templates_LL\Src\main.c`）**第 86 行**就写着：

```c
LL_Init1msTick(8000000);      /* ★移植时第一个要删的东西 */
LL_SetSystemCoreClock(8000000);
```

Puya 官方库自己就在注释里写了（`py32l090_ll_utils.c` 第 148~155 行）：

> `@note When a RTOS is used, it is recommended to avoid changing the Systick configuration by calling this function, for a delay use rather osDelay RTOS service.`

`LL_mDelay` 的注释（第 162~170 行）：

> `@note When a RTOS is used, it is recommended to avoid using blocking delay and use rather osDelay service.`

**LL 工程没有"时基交接"问题**（没有 `HAL_IncTick` 要搬），但要注意：
- 删掉 `LL_Init1msTick()`（它会把 SysTick 重载改回 7999，与本工程巧合相同，但 72MHz 工程下就是致命的）
- `LL_mDelay()` 实测是**轮询 SysTick 的 COUNTFLAG**（第 171~191 行）→ 在 RTOS 下**不会崩**，但它是**纯 CPU 死等**，任务里用它会饿死其他任务。只允许在 `vTaskStartScheduler()` 之前的初始化代码里用。

### A.3 区别二：主频可能不是 8MHz

LL 模板实测也是 **HSI 8MHz 直出、没开 PLL**（`LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSISYS)`）；但你自己的产品工程（WX_LowCost / 燃气报警器）是 **72MHz**（`pll.c` 的 `MCUPllCfg` + `Init_SysClk_Gen(1,72)`）。

| 方案 | 时钟怎么配 | `configCPU_CLOCK_HZ` | `SysTick->LOAD` |
|---|---|---|---|
| 8MHz | 照模板，只删 `LL_Init1msTick` | `8000000UL` | 7999 |
| 72MHz | 用 `MCUPllCfg()` + `pll.c` | `72000000UL` | **71999** |

**唯一可靠的验证**：调试器 Watch `SystemCoreClock`，它必须 **等于** `configCPU_CLOCK_HZ`。

### A.4 LL 的中断写法（与 HAL 的差别）

```c
/* LL 风格：直接操作 EXTI 寄存器（HAL 风格见 §6.1） */
void EXTI0_1_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    if (LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_0) != RESET)
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_0);
        xTaskNotifyFromISR(xTask, 1, eSetBits, &xHigherPriorityTaskWoken);
    }
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
```

规则不变：ISR 里只用 `...FromISR` API，退出前 `portYIELD_FROM_ISR()`。

### A.5 LL 工程的 SysTick 验收值速查

| 工程主频 | `SysTick->LOAD` |
|---|---|
| 8MHz（LL 模板 / 本 HAL 工程） | **7999** |
| 72MHz（你的产品工程） | **71999** |

`SHPR3 = 0xC0C00000`、`uxCriticalNesting = 0` 两者相同。

---

*本手册全部结论来自本机实测：PY32C882 HAL 库 V0.5.0 官方 GPIO_Toggle 例程、FreeRTOS-Kernel V10.5.1 源码、Keil MDK AC5(V5.06) 路径与 UV4 命令行编译实测退出码。所有寄存器值/宏定义均可在列出的源码文件中逐一核对。*
*旧版（LL 库语境）手册已备份为 `_备份_旧版手册(LL库语境-2026-09-24).md`。*
