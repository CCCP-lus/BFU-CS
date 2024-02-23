#include<bits/stdc++.h>
using namespace std;

class PersonInfo
{
private:
	string name;
	int age;	
public:
	PersonInfo(string name = 0, int age = 0);
	string Name();
	int Age();
	~PersonInfo();
};

PersonInfo::PersonInfo(string na, int ag)
{
	name = na;
	age = ag;
}

string PersonInfo::Name()
{
	return name;
}

int PersonInfo::Age()
{
	return age;
}

PersonInfo::~PersonInfo()
{
	
}

int main()
{
    string    name;
    int    year;
    cin >> name >> year;
    PersonInfo info(name, year);
    cout << "I am " << info.Name() << ", " << info.Age() << " years old.\n";
    return 0;
}
