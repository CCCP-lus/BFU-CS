#include<bits/stdc++.h>
using namespace std;

class child
{
private:
	string name;
	int num;
	int time;
public:
	child();
	child(string, int, int);
	friend ostream & operator<<(ostream&, const child&);
	friend istream & operator>>(istream&, child&);
	string getname();
	int getnum();
	int gettime();
	~child();
};

string child::getname()
{
	return name;
}

int child::getnum()
{
	return num;
}

int child::gettime()
{
	return time;
}

bool compare(child a, child b)
{
	if(a.getnum() > b.getnum())
		return true;
	else if(a.getnum() == b.getnum())
		return a.gettime() < b.gettime();
	else
		return false;
	
}

child::child()
{
	
}

child::child(string na, int nu, int ti)
{
	name = na;
	num = nu;
	time = ti;
}

ostream & operator<<(ostream& out, const child& chi)
{
	cout << chi.name << " " << chi.num << " " << chi.time;
	return out;
}

istream & operator>>(istream& in, child& chi)
{
	cin >> chi.name >> chi.num >> chi.time;
	return in;
}

child::~child()
{
	
}

int main()
{
    int N;
    cin>>N;
    string name;
    int fish, time;
    vector<child> v;
    for(int i=0;i<N;i++)
	{
        cin>>name>>fish>>time;
        v.push_back(child(name,fish,time));
    }

    sort(v.begin(),v.end(),compare);

    for(int i=0;i<N;i++)
        cout<<v[i]<<'\n';

    return 0;
}
