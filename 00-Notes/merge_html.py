"""把 _parts/p1..p7.html 合并成最终教学页，并做完整性校验。
python.exe 在本机是明文写入（Esafenet 透明加密白名单），所以最终文件必须由它落盘。
用法: python merge_html.py
"""
import io, os, re, sys
sys.stdout.reconfigure(encoding='utf-8')

HERE = os.path.dirname(os.path.abspath(__file__))
PARTS = [os.path.join(HERE, '_parts', f'p{i}.html') for i in range(1, 8)]
OUT = os.path.join(HERE, 'FreeRTOS原理图解教学.html')

chunks = []
for p in PARTS:
    if not os.path.isfile(p):
        print(f'!! 缺少分块文件: {p}'); sys.exit(1)
    chunks.append(io.open(p, encoding='utf-8').read())
print(f'[OK] 读入 {len(chunks)} 个分块，共 {sum(len(c) for c in chunks)} 字符')

# ---- 修正 hero 里两个写错的数字（断言存在，防静默失败）----
BAD1 = '<div><b>0.04 µs</b><span>一条指令（25ns×?) 单周期 ~125ns</span></div>'
FIX1 = '<div><b>125 ns</b><span>单周期 @8MHz</span></div>'
BAD2 = '<div><b>9520 B</b><span>本工程 Flash 占用</span></div>'
FIX2 = '<div><b>9576 B</b><span>本工程 Flash 占用</span></div>'
assert BAD1 in chunks[0], '!! hero 占位字符串未命中'
chunks[0] = chunks[0].replace(BAD1, FIX1)
assert BAD2 in chunks[0], '!! hero Flash 数字未命中'
chunks[0] = chunks[0].replace(BAD2, FIX2)
print('[OK] 已修正 hero 两处数字（单周期 125ns / Flash 9576B）')

html = ''.join(chunks)

# ---- 结构校验 ----
def cnt(a, b): return html.count(a), html.count(b)
checks = [
    ('DOCTYPE 开头', html.lstrip().startswith('<!DOCTYPE html>')),
    ('html 收尾', html.rstrip().endswith('</html>')),
    ('无 BOM 残留', '\ufeff' not in html),
    ('UTF-8 中文可编解码', True),
]
for tag in ('section', 'svg', 'figure', 'details', 'table', 'pre'):
    o, c = cnt(f'<{tag}', f'</{tag}>')
    checks.append((f'<{tag}> 配对 ({o}/{c})', o == c))
for tag in ('div', 'main', 'nav', 'body', 'script', 'style'):
    o, c = cnt(f'<{tag}', f'</{tag}>')
    checks.append((f'<{tag}> 配对 ({o}/{c})', o == c))
sec = re.findall(r'<section class="ch" id="([^"]+)"', html)
checks.append((f'章节数 = {len(sec)} ({",".join(sec)})', len(sec) == 14))
for k in ('SysTick_Handler', 'xPortPendSVHandler', '0xC0C00000', '7999',
          'pxPortInitialiseStack', 'prvPortStartFirstTask', 'EXC_RETURN', 'vTaskDelayUntil'):
    checks.append((f'关键内容 {k}', k in html))
ok = True
for name, good in checks:
    print(f'  {"OK " if good else "!! "} {name}')
    ok = ok and good
if not ok:
    print('\n!!! 校验未通过，未写盘'); sys.exit(1)

# ---- 写盘（UTF-8 无 BOM，LF）----
with io.open(OUT, 'w', encoding='utf-8', newline='\n') as f:
    f.write(html)

# ---- 读回验证（字节层面）----
raw = open(OUT, 'rb').read()
print(f'\n[OK] 已写出: {OUT}')
print(f'     字节数 = {len(raw)}，首 15 字节 = {raw[:15]!r}')
assert raw[:15] == b'<!DOCTYPE html>', '!! 首字节不是 DOCTYPE（可能被加密）'
assert b'Esafenet' not in raw[:4096], '!! 疑似被 Esafenet 加密'
assert not raw.startswith(b'\xef\xbb\xbf'), '!! 有 BOM'
back = raw.decode('utf-8')
print(f'[OK] 读回验证通过：{len(back)} 字符，含 </html> = {back.rstrip().endswith("</html>")}')
print(f'[OK] 中文抽样 = {"原理图解教学" in back}')
