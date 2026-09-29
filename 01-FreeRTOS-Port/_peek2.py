import sys
sys.stdout.reconfigure(encoding='utf-8')
P = r'D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle\FreeRTOS\Source\portable\RVDS\ARM_CM0\port.c'
raw = open(P, 'rb').read()
txt = raw.decode('utf-8', errors='replace')
lines = txt.splitlines()

import re
def find(pat):
    for i, l in enumerate(lines):
        if re.search(pat, l):
            return i + 1
    return None

marks = [
    ('pxPortInitialiseStack', r'StackType_t \*pxPortInitialiseStack'),
    ('prvStartFirstTask',     r'void prvStartFirstTask'),
    ('xPortPendSVHandler',    r'void xPortPendSVHandler'),
    ('vPortEnterCritical',    r'void vPortEnterCritical'),
    ('xPortSysTickHandler',   r'void xPortSysTickHandler'),
]
pos = {name: find(p) for name, p in marks}
print('函数位置:', pos)

for name, a in [('① pxPortInitialiseStack（伪造初始栈帧）', pos['pxPortInitialiseStack']),
                ('② prvStartFirstTask（启动第一个任务，不用 SVC）', pos['prvStartFirstTask']),
                ('③ xPortPendSVHandler（任务切换的全部秘密）', pos['xPortPendSVHandler']),
                ('④ vPortEnterCritical + xPortSysTickHandler', pos['vPortEnterCritical'])]:
    b = a + 52
    print(f'\n{"="*70}\n{name}   (port.c 行 {a}~{b})\n{"="*70}')
    for i in range(a - 1, min(b, len(lines))):
        print(f'{i+1:5d}| {lines[i]}')
