import requests
from bs4 import BeautifulSoup
import operator

# 绕过网站检查
header = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.67 Safari/537.36 Edg/87.0.664.47'}
html = requests.get('https://so.gushiwen.org/gushi/tangshi.aspx', headers = header)

# 得到网站源代码
res = html.content.decode()

# 得到网站源代码后分层提取出待筛选字段
res = html.content.decode()
soup = BeautifulSoup(res, 'lxml')
paragraph = soup.find("div", class_ = "main3")
select = paragraph.find_all("span")

for i in range(len(select)):
    select[i] = str(select[i])
    select[i] = select[i].split("(")[-1]
    select[i] = select[i].split(")")[0]

result = {}

for i in select:
    if i in result.keys():
        result[i] += 1
    else:
        result[i] = 1

result = sorted(result.items(), key = operator.itemgetter(1), reverse = True)

for i in range(10):
    print("排名第{0}的诗人是{1}，共{2}首作品".format(i + 1, result[i][0], result[i][1]))

# print(type(select[1]))



