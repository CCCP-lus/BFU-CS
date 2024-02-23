from matplotlib import pyplot as plt
import numpy as np

# 不修改字体的话，会因为默认字体无法识别中文而报错
plt.rcParams["font.sans-serif"] = ["SimHei"]

sites = ['亚马逊', '当当网', '中国图书网', '京东', '天猫']
price =np.array([39.5, 39.9, 45.4, 38.9, 33.34])
plt.barh(sites, width = price)
plt.title('图书比价')
for index, value in enumerate(price):
    plt.text(value, index, str(value))
plt.show()