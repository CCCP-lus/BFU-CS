import pandas

drinks = pandas.read_csv('drinks.csv', keep_default_na = False)

dis = drinks.groupby('continent').describe()

print(dis.iloc[:,[1,5]])
print(dis.iloc[:,[9,13]])
print(dis.iloc[:,[17,21]])
print(dis.iloc[:,[25,29]])