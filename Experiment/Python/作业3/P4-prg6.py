h = float(100)
tol = float(0)
last = float(0)
for i in range(0, 10):
    tol += h
    h /= 2
    tol += h
    last = h
print("第十次落地经过 " + str(tol - last) + " 米")
print("第十次反弹 " + str(last) + " 米")