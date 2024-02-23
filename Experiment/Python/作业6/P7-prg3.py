import os
import shutil
import zipfile

# 待处理文件的路径
FILEPATH = './py'

# 获取指定路径下所有文件
files = os.listdir(FILEPATH)

# 存符合条件文件
List = []

# 筛选所有后缀为.py的文件
for filename in files:
    if os.path.splitext(filename)[1] == ".py":
        List.append(filename)

# 文件夹目标地址
TARGET = './python_code'

# 复制.py文件至目标地址
for name in List:
    shutil.copy(FILEPATH + "/" + name, TARGET + "/" + name)

# 压缩文件命名
ZIP = './python_code.zip'

# 新建并将TARGET文件夹中内容写入压缩包中
ZIPFILE = zipfile.ZipFile(ZIP, 'w')
ZIPFILE.write(TARGET, 'python_code')
for name in List:
    ZIPFILE.write(TARGET + '/' + name)
ZIPFILE.close()
print("Operation is done!")