import numpy
from sklearn.datasets import load_iris

iris = load_iris()

print('The size of the data set is ', iris['data'].shape)

print('The data type of this data set is', iris['data'].dtype)

print('The maximum value of each column is ', numpy.max(iris['data'], axis = 0))
print('The minimum value of each column is ', numpy.min(iris['data'], axis = 0))
print('The average of each column is ', numpy.average(iris['data'], axis = 0))