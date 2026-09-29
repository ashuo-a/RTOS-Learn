"""给 GPIO_Toggle 工程的 C 编译器加 --no-multibyte-chars，消除中文注释引起的
   AC5 警告 #870-D: invalid multibyte character sequence。
   只改 <Cads><VariousControls><MiscControls>（不动 Aads / LDads 的两个空项）。
   同时顺带打印 Program Size 与告警统计所需的日志开关状态。
"""
import os, sys, shutil
sys.stdout.reconfigure(encoding='utf-8')

PROJ = r'D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle'
UX = os.path.join(PROJ, 'MDK-ARM', 'Project.uvprojx')

txt = open(UX, encoding='utf-8').read()

# 定位 Cads 段，只在其中替换
i_cads = txt.index('<Cads>')
i_aads = txt.index('<Aads>')
cads = txt[i_cads:i_aads]
print('--- 修改前 Cads 段内的 MiscControls ---')
for line in cads.splitlines():
    if 'MiscControls' in line or 'IncludePath' in line:
        print(' ', line.strip()[:120])

OLD = '<MiscControls></MiscControls>'
NEW = '<MiscControls>--no-multibyte-chars</MiscControls>'

assert cads.count(OLD) == 1, f'!! Cads 段内空 MiscControls 数量异常: {cads.count(OLD)}'
assert '--no-multibyte-chars' not in txt, '!! 已经加过了，停止'

if not os.path.exists(UX + '.bak2'):
    shutil.copy2(UX, UX + '.bak2')
    print('[OK] 备份 -> Project.uvprojx.bak2')

cads_new = cads.replace(OLD, NEW)
txt = txt[:i_cads] + cads_new + txt[i_aads:]
open(UX, 'w', encoding='utf-8', newline='').write(txt)
print('[OK] 已在 Cads/VariousControls/MiscControls 写入 --no-multibyte-chars')

import xml.etree.ElementTree as ET
root = ET.parse(UX).getroot()
print('[OK] XML 解析通过')
print('回读 MiscControls =', root.findtext('.//Cads/VariousControls/MiscControls'))
print('回读 Aads MiscControls =', repr(root.findtext('.//Aads/VariousControls/MiscControls')))
print('回读 LDads Misc =', repr(root.findtext('.//LDads/Misc')))
print('分组数 =', len(root.findall('.//Groups/Group')))
