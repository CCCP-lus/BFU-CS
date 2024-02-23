#include<bits/stdc++.h>
using namespace std;

class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer(const string &, const string &, bool);
	string FirstName() const;
	string LastName() const;
	bool HasTable() const;
};

class RatedPlayer : public TableTennisPlayer
{
private:
	int rating;
public:
	RatedPlayer(int, const string&, const string&, bool);
	int Rating();
};

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht)
{
	this ->firstname = fn;
	this ->lastname = ln;
	this ->hasTable = ht;
}
//�вι��캯�� 
string TableTennisPlayer::FirstName() const
{
	return this ->firstname;
}
//������ 
string TableTennisPlayer::LastName() const
{
	return this ->lastname;
}
//������ 
bool TableTennisPlayer::HasTable() const
{
	return this ->hasTable;
}
//�����������״̬ 
RatedPlayer::RatedPlayer(int _ra, const string& _fn, const string& _ln, bool _ht) : TableTennisPlayer(_fn, _ln, _ht)
{
	this ->rating = _ra;
}
//�вι��캯��
int RatedPlayer::Rating()
{
	return this ->rating;
}
//����ѡ�ֵ÷� 
int main()
{
	string firstname, lastname;
	bool hasTable;
	int rating;
	char flag;
	while(cin>>flag)
	{
		if(flag=='T')
		{
			cin>>firstname>>lastname>>hasTable;
			TableTennisPlayer tp(firstname,lastname,hasTable);
			if(tp.HasTable())
				cout<<tp.FirstName()<<" "<<tp.LastName()<<" has a table.\n";
			else
				cout<<tp.FirstName()<<" "<<tp.LastName()<<" hasn't a table.\n";
		} 
		else if(flag=='R')
		{
			cin>>firstname>>lastname>>hasTable>>rating;
			RatedPlayer rp(rating,firstname,lastname,hasTable);
			if(rp.HasTable())
				cout<<rp.FirstName()<<" "<<rp.LastName()<<" has a table. The rating is "<<rp.Rating()<<".\n";
			else
				cout<<rp.FirstName()<<" "<<rp.LastName()<<" hasn't a table. The rating is "<<rp.Rating()<<".\n";
		}
	}
	return 0;
}
