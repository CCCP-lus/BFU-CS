#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
	int number;
	char name[20];
	char sex;
	int age;
public:
	void set(int a, char *b, char c, int d);
	void show();
};

void Student::set(int a, char *b, char c, int d)
{
	number = a;
	strcpy(name, b);
	sex = c;
	age = d;
}
void Student::show()
{
	cout<<number<<'\t'<<name<<'\t'<<sex<<'\t'<<age<<endl;
}