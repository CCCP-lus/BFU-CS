import pandas

drinks = pandas.read_csv('drinks.csv', keep_default_na = False)

dis = drinks.groupby('continent').describe()

print(dis.iloc[:,[9,15,11]])