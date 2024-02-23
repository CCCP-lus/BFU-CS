n = int(input("请输入工资："))
if n < 0:
    print("非法输入")
elif n <= 3000:
    x = n * 0.005
    print("所需要缴纳党费为 " + str(x) +" 元")
elif n <= 5000:
    x = n * 0.01
    print("所需要缴纳党费为 " + str(x) +" 元")
elif n <= 10000:
    x = n * 0.015
    print("所需要缴纳党费为 " + str(x) +" 元")
else:
    x = n * 0.02
    print("所需要缴纳党费为 " + str(x) +" 元")