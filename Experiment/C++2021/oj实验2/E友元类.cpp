#include<bits/stdc++.h>
using namespace std;

class Subject //选课类
{
private:
	double score[3]; //3门课成绩
	const int SMath, SEng, SCpp; //3门课的学分，分别为4、2、2
public:
	Subject(double score_math = 0, double score_eng = 0, double score_cpp = 0);
	void Input(); //输入3门课的成绩
	friend class Student; //友元类
};

class Student
{
private:
	string ID; //学号
	string name; //姓名
	double GPA; //平均学分积=（成绩1x学分1+成绩2x学分2+成绩3x学分3）/（学分1+学分2+学分3）
public:
	Student(string id = "00000", string na = "Noname");
	void CalculateGPA(const Subject &sub); //计算平均学分积
	void Input(); //输入学号和姓名
	void Show(const Subject &sub)const; //输出所有信息
};

Subject::Subject(double score_math, double score_eng, double score_cpp): SMath(score_math), SEng(score_eng), SCpp(score_cpp)//3门课的学分，分别为4、2、2
{
	
}

void Subject::Input()//输入3门课的成绩
{
	double a[3];
	for(int i = 0; i < 3; i++)
	{
		cin >> a[i];
		this ->score[i] = a[i];
	}
}

Student::Student(string id, string na)//有参构造函数 
{
	this ->ID = id;
	this ->name = na;
}

void Student::CalculateGPA(const Subject &sub)//计算平均学分积 
{
	double sum = 0;
	sum += (sub.score[0] * sub.SMath + sub.score[1] * sub.SEng + sub.score[2] * sub.SCpp);
	this ->GPA = sum / 8.0;
}

void Student::Input()//输入学号和姓名 
{
	string na, id;
	cin >> id >> na;
	ID = id;
	name = na;
}

void Student::Show(const Subject &sub)const//输出所有信息
{
	cout << "ID: " << ID << "," << " Name: " << name << endl;
	cout << "Math " << "Eng " << "Cpp" << endl;
	cout << sub.score[0] <<' '<< sub.score[1] << ' ' << sub.score[2] << ' ' << endl;
	cout << "GPA: " << GPA << endl;
}

int main()
{
	int n; //学生人数
	cin >> n;
	Student *stu = new Student[n];
	Subject *sub = new Subject[n];
	for (int i = 0; i < n; i++)
	{
		stu[i].Input();
		sub[i].Input();
	}
	for (int i = 0; i < n; i++)
	{
		stu[i].CalculateGPA(sub[i]);
		stu[i].Show(sub[i]);
	}
	delete[] stu;
	delete[] sub;
	return 0;
}
