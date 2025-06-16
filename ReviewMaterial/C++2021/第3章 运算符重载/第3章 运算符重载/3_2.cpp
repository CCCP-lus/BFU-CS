#include<iostream>
#include<cstring>
using namespace std;


class Student{
private:
	int number;
	char name[20];
	char sex;
	int age;
public:
	Student(int, char *, char, int);
	friend istream & operator>>(istream & stream, Student & stu);
	friend ostream & operator<<(ostream & stream, const Student & stu);
};

Student::Student(int n, char *name, char s, int a)
{
	number = n;
	strcpy(this->name, name);
	sex = s;
	age = a;
}

istream & operator>>(istream &stream, Student &stu)
{
	stream >> stu.number >> stu.name >> stu.sex >> stu.age;
	return stream;
}

ostream & operator<<(ostream &stream, const Student &stu)
{
	stream << stu.number << " " << stu.name << " " << stu.sex << " " << stu.age << endl;
	return stream;
}

int main()
{
	Student stu(101, "wang", 'M', 20);
	cout << "当前学生信息:";
	cout << stu;
	cout << "输入新的学生信息：";
	cin >> stu;
	cout << "新的学生信息：";
	cout << stu;

	return 0;
}

+++++++++++++++++++++++

#include<iostream>
#include<string>
using namespace std;

class Student{
private:
	int number;
	string name;
	char sex;
	int age;
public:
	Student(int n = 0, string name = "", char s = '?', int a = 0);
	friend istream & operator>>(istream & stream, Student & stu);
	friend ostream & operator<<(ostream & stream, const Student & stu);
};

Student::Student(int n, string name, char s, int a)
{
	number = n;
	this->name = name;
	sex = s;
	age = a;
}

istream & operator>>(istream & stream, Student & stu)
{
	stream >> stu.number >> stu.name >> stu.sex >> stu.age;
	return stream;
}

ostream & operator<<(ostream & stream, const Student & stu)
{
	stream << stu.number << " " << stu.name << " " << stu.sex << " " << stu.age;
	return stream;
}

int main()
{
	Student stu;
	cout << "输入学生信息：";
	cin >> stu;
	cout << "学生信息：";
	cout << stu << endl;

	return 0;
}

