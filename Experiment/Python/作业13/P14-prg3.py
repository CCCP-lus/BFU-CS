import pandas
from sklearn import metrics
from sklearn import preprocessing
from sklearn.linear_model import ElasticNet
from sklearn.linear_model import Lasso
from sklearn.linear_model import LogisticRegression
from sklearn.linear_model import Ridge
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVR
from sklearn.tree import DecisionTreeClassifier


# 格式化输出函数
def analyse(test, pred):
    print("均方误差: %.3f" % (metrics.mean_squared_error(test, pred)))
    print("平均绝对误差: %.3f" % (metrics.mean_absolute_error(test, pred)))
    print("中值绝对误差: %.3f" % (metrics.median_absolute_error(test, pred)))
    print("可解释方差: %.3f" % (metrics.explained_variance_score(test, pred)))
    print("R方: %.3f" % (metrics.r2_score(test, pred)))
    print()

FILE = "winequalitywhite.csv"
data = pandas.read_csv(FILE, delimiter=';')

# 划分训练集和数据集

X = data.iloc[:, :-1]
y = data.iloc[:, -1]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=123)

# 逻辑回归
model = LogisticRegression(multi_class='multinomial', solver='lbfgs',max_iter=3500)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("多元逻辑回归"))
analyse(y_test, y_pred)

# 岭回归
model = Ridge(alpha= 0.5)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("岭回归"))
analyse(y_test, y_pred)

# 套索回归
model = Lasso(alpha=0.1)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("套索回归"))
analyse(y_test, y_pred)

# 弹性网络回归
model = ElasticNet()
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("弹性网络回归"))
analyse(y_test, y_pred)

# KNN
model = KNeighborsClassifier()
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("KNN"))
analyse(y_test, y_pred)

# 决策树
model = DecisionTreeClassifier()
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("决策树"))
analyse(y_test, y_pred)

# SVM
scaler = preprocessing.StandardScaler()
X = scaler.fit_transform(data.iloc[:, :-1])
y = scaler.fit_transform(data.iloc[:, -1].values.reshape(-1, 1))
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=123)
model = SVR(kernel='linear', C=1.0)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("SVM"))
analyse(y_test, y_pred)
