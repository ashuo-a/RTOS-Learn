import sys
sys.stdout.reconfigure(encoding='utf-8')
P = r'D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle\FreeRTOS\Source\portable\RVDS\ARM_CM0\port.c'
lines = open(P, 'rb').read().decode('utf-8', errors='replace').splitlines()
print(f'port.c 共 {len(lines)} 行')
for a, b, t in [(95, 200, 'A) 声明 + pxPortInitialiseStack/开始任务相关'), (200, 300, 'B) prvStartFirstTask + xPortPendSVHandler/xPortSysTickHandler')]:
    print(f'\n{"="*72}\n{t}   (行 {a}~{b})\n{"="*72}')
    for i in range(a - 1, min(b, len(lines))):
        print(f'{i+1:5d}| {lines[i]}')
