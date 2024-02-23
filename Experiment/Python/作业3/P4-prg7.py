n = int(input("请输入待输入的字符串个数："))
for i in range(n):
    tol = int(0)
    s = str(input("请输入第 %d 个字符串：" %(i + 1)))
    l = s.split()
    for j in range(len(l)):
        tol += len(l[j])
    print(tol)