import os, re, sys, shutil, xml.etree.ElementTree as ET
sys.stdout.reconfigure(encoding='utf-8')

PROJ = r'D:\RTOS-Learn\01-FreeRTOS-Port\GPIO_Toggle'
UX   = os.path.join(PROJ, 'MDK-ARM', 'Project.uvprojx')

OLD_INC = r'..\Inc;..\..\..\..\..\..\Drivers\BSP\PY32C882xx_Start_Kit;..\..\..\..\..\..\Drivers\CMSIS\Include;..\..\..\..\..\..\Drivers\CMSIS\Device\PY32C882\Include;..\..\..\..\..\..\Drivers\PY32C882_HAL_Driver\Inc'
NEW_INC = (r'..\Inc'
           r';..\Drivers\BSP\PY32C882xx_Start_Kit'
           r';..\Drivers\CMSIS\Include'
           r';..\Drivers\CMSIS\Device\PY32C882\Include'
           r';..\Drivers\PY32C882_HAL_Driver\Inc'
           r';..\FreeRTOS\include'
           r';..\FreeRTOS\Source\portable\RVDS\ARM_CM0')

OLD_DRV = '..\\..\\..\\..\\..\\..\\Drivers\\'
NEW_DRV = '..\\Drivers\\'

GROUPS = '''        <Group>
          <GroupName>FreeRTOS_Core</GroupName>
          <Files>
            <File>
              <FileName>tasks.c</FileName>
              <FileType>1</FileType>
              <FilePath>..\\FreeRTOS\\Source\\tasks.c</FilePath>
            </File>
            <File>
              <FileName>queue.c</FileName>
              <FileType>1</FileType>
              <FilePath>..\\FreeRTOS\\Source\\queue.c</FilePath>
            </File>
            <File>
              <FileName>list.c</FileName>
              <FileType>1</FileType>
              <FilePath>..\\FreeRTOS\\Source\\list.c</FilePath>
            </File>
            <File>
              <FileName>timers.c</FileName>
              <FileType>1</FileType>
              <FilePath>..\\FreeRTOS\\Source\\timers.c</FilePath>
            </File>
          </Files>
        </Group>
        <Group>
          <GroupName>FreeRTOS_Port</GroupName>
          <Files>
            <File>
              <FileName>port.c</FileName>
              <FileType>1</FileType>
              <FilePath>..\\FreeRTOS\\Source\\portable\\RVDS\\ARM_CM0\\port.c</FilePath>
            </File>
          </Files>
        </Group>
        <Group>
          <GroupName>FreeRTOS_Heap</GroupName>
          <Files>
            <File>
              <FileName>heap_4.c</FileName>
              <FileType>1</FileType>
              <FilePath>..\\FreeRTOS\\Source\\portable\\MemMang\\heap_4.c</FilePath>
            </File>
          </Files>
        </Group>
        <Group>
          <GroupName>Config</GroupName>
          <Files>
            <File>
              <FileName>FreeRTOSConfig.h</FileName>
              <FileType>5</FileType>
              <FilePath>..\\Inc\\FreeRTOSConfig.h</FilePath>
            </File>
            <File>
              <FileName>app_rtos_hooks.c</FileName>
              <FileType>1</FileType>
              <FilePath>..\\Src\\app_rtos_hooks.c</FilePath>
            </File>
          </Files>
        </Group>
'''

ANCHOR = '''        <Group>
          <GroupName>Doc</GroupName>'''

# ---------- 1) 备份 ----------
if not os.path.exists(UX + '.bak'):
    shutil.copy2(UX, UX + '.bak')
    print('[OK] 已备份 uvprojx ->', os.path.basename(UX) + '.bak')
else:
    print('[--] uvprojx.bak 已存在，不覆盖')

txt = open(UX, encoding='utf-8').read()
orig = txt

# ---------- 2) 断言锚点存在（防吞行/静默失败）----------
print('\n=== 锚点检查 ===')
assert OLD_INC in txt, '!! IncludePath 原串未找到'
print('[OK] IncludePath 原串命中')
assert OLD_DRV in txt, '!! Drivers 相对路径原串未找到'
print(f'[OK] 六层 Drivers 相对路径命中 {txt.count(OLD_DRV)} 处')
assert ANCHOR in txt, '!! <GroupName>Doc</GroupName> 锚点未找到'
print('[OK] Doc 分组锚点命中')
assert 'FreeRTOS_Core' not in txt, '!! 已经加过分组了，停止（避免重复插入）'
print('[OK] 尚无 FreeRTOS 分组（未重复插入）')

# ---------- 3) 改 include 路径 ----------
txt = txt.replace(OLD_INC, NEW_INC)
# ---------- 4) 改所有 Drivers 文件路径 ----------
n_drv = txt.count(OLD_DRV)
txt = txt.replace(OLD_DRV, NEW_DRV)
print(f'\n[OK] 改写 Drivers 文件路径 {n_drv} 处 -> ..\\Drivers\\...')

# ---------- 5) 插入 4 个分组 ----------
txt = txt.replace(ANCHOR, GROUPS + ANCHOR)
print('[OK] 已在 Doc 分组前插入 4 个 FreeRTOS 分组')

# ---------- 6) 写回 ----------
assert txt != orig, '!! 内容未变化'
open(UX, 'w', encoding='utf-8', newline='').write(txt)
print('[OK] 已写回 uvprojx')

# ---------- 7) XML 合法性 + 结构回读 ----------
print('\n=== 回读验证（XML 解析 + 结构打印）===')
root = ET.parse(UX).getroot()
print('[OK] XML 解析通过, SchemaVersion =', root.findtext('SchemaVersion'))
tg = root.find('.//Target')
print('TargetName =', tg.findtext('TargetName'), '| Device =', tg.findtext('TargetCommonOption/Device'),
      '| uAC6 =', tg.findtext('uAC6'), '| pCCUsed =', tg.findtext('pCCUsed'))
print('Define =', tg.findtext('.//Cads/VariousControls/Define'))
inc = tg.findtext('.//Cads/VariousControls/IncludePath')
print('IncludePath 分段:')
for i, p in enumerate(inc.split(';')):
    full = os.path.normpath(os.path.join(PROJ, 'MDK-ARM', p))
    print(f'   [{i}] {p:48s} -> {"OK" if os.path.isdir(full) else "!!! 不存在"}')
print('\n分组与文件:')
for g in root.findall('.//Groups/Group'):
    files = [f.findtext('FilePath') for f in g.findall('Files/File')]
    print(f'  {g.findtext("GroupName"):28s} ({len(files)} 个)')
    for fp in files:
        full = os.path.normpath(os.path.join(PROJ, 'MDK-ARM', fp))
        print(f'      {"OK " if os.path.isfile(full) else "!! "} {fp}')
