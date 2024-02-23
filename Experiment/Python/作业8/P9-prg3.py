import requests
from bs4 import BeautifulSoup

# 绕过网站检查
header = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.67 Safari/537.36 Edg/87.0.664.47'}
html = requests.get('https://so.gushiwen.org/gushi/tangshi.aspx', headers = header)

# 得到网站源代码后分层提取出待筛选字段
res = html.content.decode()
soup = BeautifulSoup(res, 'lxml')
paragraph = soup.find("div", class_ = "main3")
select = paragraph.find_all("div", class_ = "typecont")

name = list(range(7))
num = list(range(7))
for i in range(7):
    name[i] = str(select[i].find("strong"))
    name[i] = name[i].split(">")[1]
    name[i] = name[i].split("<")[0]
    num[i] = len(select[i].find_all("a", target = "_blank"))
    print("{0} 共有 {1} 首".format(name[i], num[i]))
