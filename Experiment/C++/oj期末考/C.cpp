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
    sportsMeet freshman_sports;   // 新生运动会 
    string sport_name;   // 某项运动名称 
    int number_of_participants; // 参加某项运动的人数 
    while(cin>>sport_name>>number_of_participants && number_of_participants!=0){
        freshman_sports.add_sport(sport(sport_name,number_of_participants)); // 添加某项运动到运动会项目列表中 
    }

    int number = sportsMeet::get_number();   // 运动会中的项目数 
    vector<sport> sports = freshman_sports.get_sports();  // 运动会项目列表 

    cout<<number<<'\n';   // 输出运动会的项目数 
    for(int i=0;i<number;i++)  // 输出每个运动项目的名称和参加人数 
        cout<<sports[i].get_name()<<' '<<sports[i].get_number_of_participants()<<'\n';

    return 0;
}
