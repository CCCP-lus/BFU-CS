#include<bits/stdc++.h>
using namespace std;

class Hotel
{
private:
	int Num;
	string Name;
//	static int sum;
public:
	void add(string na);//增加用户 
	static int getTotal();//返回总人数
	string getName();//返回用户姓名 
	void print();//输出数据 
	static int sum;//总人数 
};

int Hotel::sum = 0;//初值 

void Hotel::add(string na)//增加用户
{
	sum++;//总人数+1 
	this -> Num = sum; //编号赋值 
	this -> Name = na;//姓名赋值 
}

int Hotel::getTotal()//返回总人数
{
	return sum;
}

string Hotel::getName()//返回用户姓名
{
	return this ->Name;
}

void Hotel::print()//输出数据 
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
