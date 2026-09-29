import re, sys, io
sys.stdout.reconfigure(encoding='utf-8')

p = r'D:\RTOS-Learn\01-FreeRTOS-Port\阶段1-FreeRTOS移植手册.md'
txt = open(p, encoding='utf-8').read()
lines = txt.splitlines()

# 找附录 A 的分界
idx = next(i for i, l in enumerate(lines) if l.startswith('## 附录 A'))
body = '\n'.join(lines[:idx])
appx = '\n'.join(lines[idx:])

print(f'总行数 {len(lines)}；正文 1~{idx} 行，附录 A 从第 {idx+1} 行起\n')

pat = re.compile(r'LL_[A-Za-z_]+|LL 库|LL库|LL 模板')
print('=== 正文（HAL 主线）里的 LL 痕迹 ===')
hits = [(i+1, l.strip()) for i, l in enumerate(lines[:idx]) if pat.search(l)]
if not hits:
    print('  (无)')
for n, l in hits:
    print(f'  {n:4d}| {l[:100]}')

print('\n=== 附录 A 里的 LL 内容（应当集中在这里）===')
ah = [(i+idx+1, l.strip()) for i, l in enumerate(lines[idx:]) if pat.search(l)]
print(f'  共 {len(ah)} 行（附录 A 就是给 LL 工程用的，这里是应该有的）')

print('\n=== 关键内容自检 ===')
need = {
    '标题已是 HAL':            '# 阶段 1：FreeRTOS 移植手册（PY32C882 · Keil MDK · **HAL 库**）',
    'HAL_IncTick 交接章节':    'HAL_IncTick() 搬进 tick 钩子',
    'HAL_Delay 卡死条目':      'HAL_Delay()` 卡死',
    'UV4 命令行验证':          'Start-Process -FilePath $uv',
    '8MHz/SysTick=7999':       'SysTick->LOAD`(0xE000E014) 必须是 **7999**',
    'configMINIMAL_STACK_SIZE':'#error Missing definition: configMINIMAL_STACK_SIZE',
    '六层路径断裂':            '..\\..\\..\\..\\..\\..\\Drivers',
    'fputc 可用':              'fputc',
    '附录 A 存在':             '## 附录 A：LL 库工程的差异',
}
for k, s in need.items():
    print(f'  {"OK " if s in txt else "!! "} {k}')

print('\n=== 章节结构 ===')
for i, l in enumerate(lines, 1):
    if re.match(r'^#{2,3} ', l):
        print(f'  {i:4d}| {l}')
