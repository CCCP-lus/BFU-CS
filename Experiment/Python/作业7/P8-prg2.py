import re

s1 = str(input("请输入中华人民共和国电话号码："))
pattern1 = re.match(r'\d{8}$', s1) or re.match(r'^0\d{2}-\d{8}$', s1)
if pattern1:
    print("中华人民共和国电话号码匹配成功")
else:
    print("中华人民共和国电话号码匹配失败")

s2 = str(input("请输入中华人民共和国邮政编码："))
pattern2 = re.match(r'\d{6}$', s2)

if pattern2:
    print("中华人民共和国邮政编码匹配成功")
else:
    print("中华人民共和国邮政编码匹配失败")

s3 = str(input("请输入网站网址："))
pattern3 = re.match(r'^https?://\w+(?:\.[^\.]+)+(?:/.+)*$', s3)

if pattern3:
    print("网站网址匹配成功")
else:
    print("网站网址匹配失败")