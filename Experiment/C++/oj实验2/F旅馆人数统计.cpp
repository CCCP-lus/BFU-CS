#include<bits/stdc++.h>
using namespace std;

class Hotel
{
private:
	int Num;
	string Name;
//	static int sum;
public:
	void add(string na);//�����û� 
	static int getTotal();//����������
	string getName();//�����û����� 
	void print();//������� 
	static int sum;//������ 
};

int Hotel::sum = 0;//��ֵ 

void Hotel::add(string na)//�����û�
{
	sum++;//������+1 
	this -> Num = sum; //��Ÿ�ֵ 
	this -> Name = na;//������ֵ 
}

int Hotel::getTotal()//����������
{
	return sum;
}

string Hotel::getName()//�����û�����
{
	return this ->Name;
}

void Hotel::print()//������� 
{
	cout << this ->Num << " " << this ->Name << " " << sum << endl;
}

int main()
{
    Hotel h[100];
    h[0].add("Susan");
    h[1].add("Peter");
    h[2].add("John");
    h[3].add("Mary");
    h[4].add("Alice");
    string name;
    cin>>name;
    for(int i=0;i<Hotel::getTotal();i++)
    {
        if(h[i].getName()==name)
        {
            h[i].print();
            break;
        }
    }
    return 0;
}
