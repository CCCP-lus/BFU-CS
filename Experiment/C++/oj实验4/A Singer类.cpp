#include<bits/stdc++.h>
using namespace std;

class Singer
{
private:
	string Name;//Ãû 
	char Gender;//ÐÔ 
	int Age;//Áä 
	double Score;//·Ö	
public:
	Singer();
	string getName();
	~Singer();
	friend istream& operator>>(istream& in, Singer& s);
	friend ostream& operator<<(ostream& out, Singer& s);
	friend bool operator >(const Singer& a, const Singer& b);
	friend bool operator ==(const Singer& a, const Singer& b);
};

Singer::Singer()
{
	
}

string Singer::getName()
{
	return Name;
}

Singer::~Singer()
{
	
}

istream& operator>>(istream& in, Singer& s)
{
	cin >> s.Name >> s.Gender >> s.Age >> s.Score;
	return in;
}

ostream& operator<<(ostream& out, Singer& s)
{
	cout << s.Name << " " << s.Gender << " " << s.Age << " " << s.Score;
	return out;
}

bool operator >(const Singer& a, const Singer& b)
{
	return a.Score > b.Score? 1: 0;
}

bool operator ==(const Singer& a, const Singer& b)
{
	return a.Score == b.Score? 1: 0;
}

int main()

{

Singer s1,s2;

cin>>s1>>s2;

cout<<s1<<"\n"<<s2<<endl;

if(s1>s2)

cout<<s1.getName()<<"'s score is higher than "<<s2.getName()<<"'s.\n";

else if(s1==s2)

cout<<s1.getName()<<"'s score is equal to "<<s2.getName()<<"'s.\n";

else

cout<<s1.getName()<<"'s score is lower than "<<s2.getName()<<"'s.\n";

return 0;


}
