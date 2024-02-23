n = int(input("请输入杨辉三角层数："))
l = [1]
for i in range(n):
    print(" ".join(str(j) for j in l).center(20))
    l = [1] + [l[i] + l[i + 1] for i in range(len(l) - 1)] + [1]
