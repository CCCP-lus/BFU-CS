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
    cin>>name_of_voiceActor>>gender_of_voiceActor; // 输入配音演员的姓名和性别 
    const voiceActor va(name_of_voiceActor,gender_of_voiceActor); // 定义一个常配音演员对象 
    cout<<"voice actor: "<<va.get_name()<<", "<<va.get_gender()<<'\n'; // 输出配音演员的姓名和性别，冒号和逗号后面各有一个空格

    string name_of_cartoon;
    cin>>name_of_cartoon; // 输入动画片的名字 
    const cartoon c(name_of_cartoon,va); // 构造一个常动画片对象 

    int number_of_seasons;
    cin>>number_of_seasons; // 输入季度动画片的季度数（比如第7季） 
    const seasonsCartoon sc(name_of_cartoon, va, number_of_seasons); // 构造一个常季度动画片对象 

    const cartoon * p = &c; // 指针p指向动画片对象c 
    p->print(); // 输出动画片的名字，所用的配音演员的名字和性别（参见输出样例） 
    cout<<'\n';

    p = &sc; // 指针p指向季度动画片对象sc 
    p->print(); // 输出季度动画片的名字，所用的配音演员的名字、性别，以及季度数（参见输出样例）

    return 0;
}
