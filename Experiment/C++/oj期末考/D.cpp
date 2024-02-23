#include<bits/stdc++.h>
using namespace std;

class voiceActor
{
private:
	string name_v;
	string sex;
public:
	voiceActor();
	voiceActor(string, string);
	string get_name() const;
	string get_gender() const;
	~voiceActor();
};

voiceActor::voiceActor()
{
	
}

voiceActor::voiceActor(string na, string se)
{
	name_v = na;
	sex = se;
}

string voiceActor::get_name() const
{
	return name_v;
}
	
string voiceActor::get_gender() const
{
	return sex;
}

voiceActor::~voiceActor()
{
	
}

class cartoon
{
protected:
	string name_c;
	voiceActor va;
public:
	cartoon();
	cartoon(string&, const voiceActor&);
	virtual void print() const;
	virtual ~cartoon();
};

cartoon::cartoon()
{
	
}

cartoon::cartoon(string& na, const voiceActor& ac)
{
	name_c = na;
	va = ac;
}

void cartoon::print() const
{
	cout << "cartoon name: " << name_c << endl;
	cout << "voice actor: " << va.get_name() << ", " << va.get_gender();
}

cartoon::~cartoon()
{
	
}

class seasonsCartoon : public cartoon
{
private:
	int num;
public:
	seasonsCartoon();
	seasonsCartoon(string&, const voiceActor&, int&);
	void print() const;
	~seasonsCartoon();
};

seasonsCartoon::seasonsCartoon()
{
	
}

seasonsCartoon::seasonsCartoon(string& na, const voiceActor& vaa, int& se)
{
	name_c = na;
	va = vaa;
	num = se;
}

void seasonsCartoon::print() const
{
	cout << "cartoon name: " << name_c << endl;
	cout << "voice actor: " << va.get_name() << ", " << va.get_gender() << endl;
	cout << "number of seasons: " << num;	
}

seasonsCartoon::~seasonsCartoon()
{
	
}

int main(){
    string name_of_voiceActor, gender_of_voiceActor; 
    cin>>name_of_voiceActor>>gender_of_voiceActor; // ����������Ա���������Ա� 
    const voiceActor va(name_of_voiceActor,gender_of_voiceActor); // ����һ����������Ա���� 
    cout<<"voice actor: "<<va.get_name()<<", "<<va.get_gender()<<'\n'; // ���������Ա���������Ա�ð�źͶ��ź������һ���ո�

    string name_of_cartoon;
    cin>>name_of_cartoon; // ���붯��Ƭ������ 
    const cartoon c(name_of_cartoon,va); // ����һ��������Ƭ���� 

    int number_of_seasons;
    cin>>number_of_seasons; // ���뼾�ȶ���Ƭ�ļ������������7���� 
    const seasonsCartoon sc(name_of_cartoon, va, number_of_seasons); // ����һ�������ȶ���Ƭ���� 

    const cartoon * p = &c; // ָ��pָ�򶯻�Ƭ����c 
    p->print(); // �������Ƭ�����֣����õ�������Ա�����ֺ��Ա𣨲μ���������� 
    cout<<'\n';

    p = &sc; // ָ��pָ�򼾶ȶ���Ƭ����sc 
    p->print(); // ������ȶ���Ƭ�����֣����õ�������Ա�����֡��Ա��Լ����������μ����������

    return 0;
}
