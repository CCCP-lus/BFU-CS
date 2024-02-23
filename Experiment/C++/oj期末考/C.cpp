#include<bits/stdc++.h>
using namespace std;

class sport
{
private:
	string name;
	int people;
public:
	sport(string, int);
	string get_name();
	int get_number_of_participants();
	~sport();
};

sport::sport(string na, int pe)
{
	name = na;
	people = pe;
}

string sport::get_name()
{
	return name;
}

int sport::get_number_of_participants()
{
	return people;
}

sport::~sport()
{
	
}

class sportsMeet
{
private:
	vector<sport> list;
public:
	sportsMeet();
	void add_sport(const sport&);
	static int get_number();
	vector<sport> get_sports();
	static int num;
};

int sportsMeet::num = 0;

sportsMeet::sportsMeet()
{
	
}

void sportsMeet::add_sport(const sport& s)
{
	list.push_back(s);
	num++;
}

int sportsMeet::get_number()
{
	return num;
}

vector<sport> sportsMeet::get_sports()
{
	return list;
}

int main(){
    sportsMeet freshman_sports;   // �����˶��� 
    string sport_name;   // ĳ���˶����� 
    int number_of_participants; // �μ�ĳ���˶������� 
    while(cin>>sport_name>>number_of_participants && number_of_participants!=0){
        freshman_sports.add_sport(sport(sport_name,number_of_participants)); // ���ĳ���˶����˶�����Ŀ�б��� 
    }

    int number = sportsMeet::get_number();   // �˶����е���Ŀ�� 
    vector<sport> sports = freshman_sports.get_sports();  // �˶�����Ŀ�б� 

    cout<<number<<'\n';   // ����˶������Ŀ�� 
    for(int i=0;i<number;i++)  // ���ÿ���˶���Ŀ�����ƺͲμ����� 
        cout<<sports[i].get_name()<<' '<<sports[i].get_number_of_participants()<<'\n';

    return 0;
}
