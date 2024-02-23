import pandas

drinks = pandas.read_csv('drinks.csv', keep_default_na = False)

mean = drinks.groupby('continent')['beer_servings'].mean()

print(mean)