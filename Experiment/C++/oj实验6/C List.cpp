#include<bits/stdc++.h>
using namespace std;

struct Student 
{
    int no;
    string name;
};

void Input(std::list<Student>& li)
{
	int n; cin >> n;
	Student s;
	for(int i = 0; i < n; i++)
	{
		cin >> s.no >> s.name;
		li.push_back(s);
	}
}

void Show(const std::list<Student>& li)
{
	for(std::list<Student>::const_iterator it = li.begin(); it != li.end(); it++)
	{
		cout << it->no << ", " << it->name << endl;
	}
}

int main()
{
    std::list<Student> li;

    Input(li); //ÊäÈë
    Show(li); //Êä³ö

    return 0;
}
