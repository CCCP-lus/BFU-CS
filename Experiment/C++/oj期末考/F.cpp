#include<bits/stdc++.h>
using namespace std;

class contestant
{
private:
	string name;
	int num;
	int time;
	int wa;
	int total;
public:
	contestant();
	void add_penalty();
	int getnum();
	int gettotal();
	friend istream & operator>>(istream&, contestant&);
	friend ostream & operator<<(ostream&, const contestant&);
	~contestant();
};

contestant::contestant()
{
	
}

void contestant::add_penalty()
{
	total = time + wa * 20;
}

int contestant::getnum()
{
	return num;
}

int contestant::gettotal()
{
	return total;
}

istream &operator>>(istream& i, contestant& c)
{
	i >> c.name >> c.num >> c.time >> c.wa;
	return i;
}

ostream & operator<<(ostream& o, const contestant& c)
{
	o << c.name << " " << c.num << " " << c.time << " " << c.wa << " " << c.total;
	return o;
}

contestant::~contestant()
{
	
}

bool compare(contestant a, contestant b)
{
	if(a.getnum() > b.getnum())
		return true;
	else if(a.getnum() == b.getnum())
		return a.gettotal() < b.gettotal();
	else return false;
}

int main(){
    int N;
    cin>>N;
    contestant c;
    vector<contestant> v;
    for(int i=0;i<N;i++){
        cin>>c;         //����ѡ��������������������ʱ�������ύ���� 
        c.add_penalty(); //���ݴ����ύ�������㷣ʱ�����ӵ�����ʱ�� 
        v.push_back(c);
    }

    sort(v.begin(),v.end(),compare);

    for(int i=0;i<N;i++)
        cout<<v[i]<<'\n'; //���ѡ��������������������ʱ�������ύ���������Ϸ�ʱ������ʱ 

    return 0;
}
