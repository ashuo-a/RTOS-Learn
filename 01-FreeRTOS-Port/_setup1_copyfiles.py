import os, shutil, sys
sys.stdout.reconfigure(encoding='utf-8')

PROJ = r'D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle'
PORT = r'D:\RTOS-Learn\01-FreeRTOS-Port'
FW   = r'C:\Users\huawei\Desktop\工作项目\Puya\PY32C882_Firmware_V0.5.0'
KERNEL_SRC = r'D:\RTOS-Learn\01-FreeRTOS-Port\PY32L090_FreeRTOS\FreeRTOS'
BACKUP = r'D:\RTOS-Learn\01-FreeRTOS-Port\_backup_GPIO_Toggle_原版裸机'

def chk(p, label):
    ok = os.path.exists(p)
    print(('[OK]  ' if ok else '[缺失]') + f' {label}: {p}')
    return ok

print('=== 0) 源路径存在性检查 ===')
must = [
    (FW + r'\Drivers\CMSIS\Include', 'CMSIS Include'),
    (FW + r'\Drivers\CMSIS\Device\PY32C882\Include', 'CMSIS Device Include'),
    (FW + r'\Drivers\PY32C882_HAL_Driver\Inc', 'HAL Inc'),
    (FW + r'\Drivers\PY32C882_HAL_Driver\Src', 'HAL Src'),
    (FW + r'\Drivers\BSP\PY32C882xx_Start_Kit', 'BSP'),
    (KERNEL_SRC + r'\Source\tasks.c', 'Kernel tasks.c'),
    (KERNEL_SRC + r'\Source\portable\RVDS\ARM_CM0\port.c', 'Kernel port.c'),
    (KERNEL_SRC + r'\include\FreeRTOS.h', 'Kernel FreeRTOS.h'),
]
allok = all(chk(p, l) for p, l in must)
if not allok:
    print('\n!!! 有必需路径不存在，中止'); sys.exit(1)

print('\n=== 1) 备份原工程（裸机版，出问题可回退）===')
if os.path.exists(BACKUP):
    print(f'备份已存在，跳过: {BACKUP}')
else:
    shutil.copytree(PROJ, BACKUP, ignore=shutil.ignore_patterns('Output', 'Objects', 'Listings', '*.uvguix*'))
    n = sum(len(f) for _, _, f in os.walk(BACKUP))
    print(f'[OK] 已备份 {n} 个文件 -> {BACKUP}')

print('\n=== 2) 拷贝精简驱动树到工程内 (GPIO_Toggle\\Drivers) ===')
pairs = [
    (FW + r'\Drivers\CMSIS\Include',                    PROJ + r'\Drivers\CMSIS\Include'),
    (FW + r'\Drivers\CMSIS\Device\PY32C882\Include',    PROJ + r'\Drivers\CMSIS\Device\PY32C882\Include'),
    (FW + r'\Drivers\PY32C882_HAL_Driver\Inc',          PROJ + r'\Drivers\PY32C882_HAL_Driver\Inc'),
    (FW + r'\Drivers\PY32C882_HAL_Driver\Src',          PROJ + r'\Drivers\PY32C882_HAL_Driver\Src'),
    (FW + r'\Drivers\BSP\PY32C882xx_Start_Kit',         PROJ + r'\Drivers\BSP\PY32C882xx_Start_Kit'),
]
for s, d in pairs:
    shutil.copytree(s, d, dirs_exist_ok=True)
    n = sum(len(f) for _, _, f in os.walk(d))
    print(f'[OK] {n:4d} 文件 <- {os.path.relpath(s, FW)}')

print('\n=== 3) 拷贝 FreeRTOS 内核到工程内 (GPIO_Toggle\\FreeRTOS) ===')
shutil.copytree(KERNEL_SRC, PROJ + r'\FreeRTOS', dirs_exist_ok=True)
n = sum(len(f) for _, _, f in os.walk(PROJ + r'\FreeRTOS'))
print(f'[OK] {n} 个文件')

print('\n=== 4) 逐条验证关键文件（照 uvprojx 即将引用的路径）===')
checks = [
    PROJ + r'\Drivers\CMSIS\Device\PY32C882\Include\py32c8xx.h',
    PROJ + r'\Drivers\CMSIS\Device\PY32C882\Include\py32c882xx.h',
    PROJ + r'\Drivers\CMSIS\Include\cmsis_armcc.h',
    PROJ + r'\Drivers\PY32C882_HAL_Driver\Inc\py32c8xx_hal.h',
    PROJ + r'\Drivers\PY32C882_HAL_Driver\Inc\py32c882_hal_conf.h',
    PROJ + r'\Drivers\PY32C882_HAL_Driver\Src\py32c882_hal.c',
    PROJ + r'\Drivers\PY32C882_HAL_Driver\Src\py32c882_hal_gpio.c',
    PROJ + r'\Drivers\PY32C882_HAL_Driver\Src\py32c882_hal_uart.c',
    PROJ + r'\Drivers\BSP\PY32C882xx_Start_Kit\py32c882xx_Start_Kit.c',
    PROJ + r'\Drivers\BSP\PY32C882xx_Start_Kit\py32c882xx_Start_Kit.h',
    PROJ + r'\FreeRTOS\Source\tasks.c',
    PROJ + r'\FreeRTOS\Source\queue.c',
    PROJ + r'\FreeRTOS\Source\list.c',
    PROJ + r'\FreeRTOS\Source\timers.c',
    PROJ + r'\FreeRTOS\Source\portable\RVDS\ARM_CM0\port.c',
    PROJ + r'\FreeRTOS\Source\portable\RVDS\ARM_CM0\portmacro.h',
    PROJ + r'\FreeRTOS\Source\portable\MemMang\heap_4.c',
    PROJ + r'\FreeRTOS\include\FreeRTOS.h',
]
bad = [p for p in checks if not chk(p, os.path.relpath(p, PROJ))]
print(f'\n结果: {len(checks)-len(bad)}/{len(checks)} 就绪' + ('' if not bad else '  <<< 有缺失!'))
