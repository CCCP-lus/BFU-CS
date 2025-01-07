#include<bits/stdc++.h>
using namespace std;

class Subject //ѡ����
{
private:
	double score[3]; //3�ſγɼ�
	const int SMath, SEng, SCpp; //3�ſε�ѧ�֣��ֱ�Ϊ4��2��2
public:
	Subject(double score_math = 0, double score_eng = 0, double score_cpp = 0);
	void Input(); //����3�ſεĳɼ�
	friend class Student; //��Ԫ��
};

class Student
{
private:
	string ID; //ѧ��
	string name; //����
	double GPA; //ƽ��ѧ�ֻ�=���ɼ�1xѧ��1+�ɼ�2xѧ��2+�ɼ�3xѧ��3��/��ѧ��1+ѧ��2+ѧ��3��
public:
	Student(string id = "00000", string na = "Noname");
	void CalculateGPA(const Subject &sub); //����ƽ��ѧ�ֻ�
	void Input(); //����ѧ�ź�����
	void Show(const Subject &sub)const; //���������Ϣ
};

Subject::Subject(double score_math, double score_eng, double score_cpp): SMath(score_math), SEng(score_eng), SCpp(score_cpp)//3�ſε�ѧ�֣��ֱ�Ϊ4��2��2
{
	
}

void Subject::Input()//����3�ſεĳɼ�
{
	double a[3];
	for(int i = 0; i < 3; i++)
	{
		cin >> a[i];
		this ->score[i] = a[i];
	}
}

Student::Student(string id, string na)//�вι��캯�� 
{
	this ->ID = id;
	this ->name = na;
}

void Student::CalculateGPA(const Subject &sub)//����ƽ��ѧ�ֻ� 
{
	double sum = 0;
	sum += (sub.score[0] * sub.SMath + sub.score[1] * sub.SEng + sub.score[2] * sub.SCpp);
	this ->GPA = sum / 8.0;
}

void Student::Input()//����ѧ�ź����� 
{
	string na, id;
	cin >> id >> na;
	ID = id;
	name = na;
}

void Student::Show(const Subject &sub)const//���������Ϣ
{
	cout << "ID: " << ID << "," << " Name: " << name << endl;
	cout << "Math " << "Eng " << "Cpp" << endl;
	cout << sub.score[0] <<' '<< sub.score[1] << ' ' << sub.score[2] << ' ' << endl;
	cout << "GPA: " << GPA << endl;
}

int main()
{
	int n; //ѧ������
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
