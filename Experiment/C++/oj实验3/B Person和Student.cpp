#include<bits/stdc++.h>
using namespace std;

class Person
{
private:
protected:
	string Name;
public:	//记得用虚函数 
	virtual void input();
	virtual void display();
	virtual ~Person();
};

class Student : public Person
{
private:
	string Number;
public:
	void input();
	void display();
	~Student();
};

void Person::input()
{
	string na;
	cin >> na;
	this ->Name = na;
}

void Person::display()
{
	cout << this ->Name << endl;
}

Person::~Person()
{
	
}

void Student::input()
{
	string na, num;
	cin >> na >> num;
	this ->Name = na;
	this ->Number = num;
}

void Student::display()
{
	cout << this ->Name << " " << this ->Number << endl;
}

Student::~Student()
{
	
}

int main()
{
	Person * p;
	p = new Person;
	p->input();
	p->display();
	delete p;
	p = new Student;
	p->input();
	p->display();
	delete p;
	return 0;
}
