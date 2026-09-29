import sys
sys.stdout.reconfigure(encoding='utf-8')
P = r'D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle\FreeRTOS\Source\portable\RVDS\ARM_CM0\port.c'
lines = open(P, 'rb').read().decode('utf-8', errors='replace').splitlines()
print(f'port.c 共 {len(lines)} 行 —— 打印 300~520')
for i in range(299, min(520, len(lines))):
    print(f'{i+1:5d}| {lines[i]}')
