import requests
import re

# 绕过网站检查
header = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.67 Safari/537.36 Edg/87.0.664.47'}
html = requests.get('https://so.gushiwen.org/gushi/tangshi.aspx', headers = header)

# 得到网站源代码
res = html.content.decode()

# 正则表达式匹配对应格式
result = re.findall(r'<span><a href="(.*?)">(.*?)</a>(.*?)</span>', res, re.S)

# 输出
print('The number of poems in this book is:', len(result))