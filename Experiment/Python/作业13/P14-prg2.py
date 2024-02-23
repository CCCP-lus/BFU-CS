import pandas
from sklearn import metrics
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import MinMaxScaler
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.naive_bayes import BernoulliNB
from sklearn.svm import SVR

# 格式化输出函数
def analyse(test, pred):
    print("ACC: %.3f" % (metrics.accuracy_score(test, pred)))
    print("召回率: %.3f" % (metrics.recall_score(test, pred)))
    print("精确率: %.3f" % (metrics.precision_score(test, pred)))
    print("F1: %.3f" % (metrics.f1_score(test, pred)))
    print()

# 读取文件
FILE = "pimaindiansdiabetes.csv"
data = pandas.read_csv(FILE)
data_head = [
    'Pregnancies', 'Glucose', 'BloodPressure', 'SkinThickness', 'Insulin', 'BMI', 'DiabetesPedigreeFunction', 'Age', 'Outcome'
]# 为表格添加表头

print("{:-^50s}".format("探索数据"))

print("文件头尾")
print(data.head())
print(data.tail())
print()
print("文件信息")
print(data.info())
print()
print("文件描述")
print(data.describe())
print()
print("数据相关性")
print(data.corr())
print()
# 数据标准化
Training = MinMaxScaler().fit(data)    # 训练规则
Applying = Training.transform(data)   # 应用规则

# 划分训练集和数据集
X = data.iloc[:, : -1]
y = data.iloc[:, -1]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=123)

# 逻辑斯蒂
model = LogisticRegression(max_iter=500)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("逻辑斯蒂"))
analyse(y_test, y_pred)

# KNN
model = KNeighborsClassifier()
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("KNN"))
analyse(y_test, y_pred)

# 决策树
model = DecisionTreeClassifier()
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("决策树"))
analyse(y_test, y_pred)

# 朴素贝叶斯
model = BernoulliNB()
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("朴素贝叶斯"))
analyse(y_test, y_pred)

# SVM
model = SVR(kernel='linear', C=1.0)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("{:-^50s}".format("SVM"))
analyse(y_test, y_pred)