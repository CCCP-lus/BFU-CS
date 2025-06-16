#include <iostream>
#include <cstring>
using namespace std;
#include "Student.h"

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