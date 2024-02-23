import os

# 待处理文件的路径
FILEPATH = './txt'

# 获取当前文件夹下的txt文件名
FILENAME = os.listdir(FILEPATH)

# 创建并写入all.txt
fw = open('./all.txt','w')

for filename in FILENAME:
    filepath = FILEPATH + '/' + filename
    for line in open(filepath):
        fw.writelines(line)
    fw.write('\n')
fw.close()
print("Operation is done")