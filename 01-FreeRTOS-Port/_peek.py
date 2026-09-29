import sys
sys.stdout.reconfigure(encoding='utf-8')

def show(path, a, b, title):
    raw = open(path, 'rb').read()
    for enc in ('utf-8', 'utf-8-sig', 'gbk', 'latin-1'):
        try:
            txt = raw.decode(enc); break
        except Exception:
            continue
    lines = txt.splitlines()
    print(f'\n########## {title}  ({path.split("\\")[-1]} 行 {a}~{b}) ##########')
    for i in range(a - 1, min(b, len(lines))):
        print(f'{i+1:5d}| {lines[i]}')

T = r'D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle\FreeRTOS\Source\tasks.c'
P = r'D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle\FreeRTOS\Source\portable\RVDS\ARM_CM0\port.c'

show(T, 2022, 2046, 'A) 谁在“调度器启动前”把 xNextTaskUnblockTime 置成 portMAX_DELAY')
show(T, 2720, 2772, 'B) xTaskIncrementTick 开头：pxDelayedTaskList 解引用')
show(P, 560, 620, 'C) port.c 的 xPortSysTickHandler 真实函数体')
