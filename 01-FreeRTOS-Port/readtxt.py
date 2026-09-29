"""通用文本读取器：自动尝试 utf-8 / gbk / utf-16，带行号，可 grep 过滤。
用法: python readtxt.py <文件路径> [关键字正则(可选)]
"""
import sys, re
sys.stdout.reconfigure(encoding='utf-8')

path = sys.argv[1]
pat = sys.argv[2] if len(sys.argv) > 2 else None

raw = open(path, 'rb').read()
text = None
used = None

# 先按 BOM/空字节分布判断 UTF-16 的字节序（Keil 的 batch build 日志是 UTF-16BE 无 BOM）
if len(raw) >= 2 and raw[:2] in (b'\xff\xfe', b'\xfe\xff'):
    used = 'utf-16'
    text = raw.decode('utf-16')
elif len(raw) >= 4 and raw[0] == 0 and raw[2] == 0:
    used = 'utf-16-be'
    text = raw.decode('utf-16-be')
elif len(raw) >= 4 and raw[1] == 0 and raw[3] == 0:
    used = 'utf-16-le'
    text = raw.decode('utf-16-le')

if text is None:
    for enc in ('utf-8-sig', 'utf-8', 'gbk', 'latin-1'):
        try:
            text = raw.decode(enc)
            used = enc
            break
        except Exception:
            continue

print(f'### {path}  ({len(raw)} B, 编码={used}) ###\n')
lines = text.splitlines()
if pat:
    rx = re.compile(pat, re.I)
    hits = [(i + 1, l) for i, l in enumerate(lines) if rx.search(l)]
    print(f'--- 命中 {len(hits)} 行 ---')
    for n, l in hits:
        print(f'{n:5d}| {l}')
else:
    for i, l in enumerate(lines, 1):
        print(f'{i:5d}| {l}')
