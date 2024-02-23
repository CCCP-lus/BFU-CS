#include<bits/stdc++.h>
using namespace std;

class easyProblem
{
private:
	int a, b;
public:
	easyProblem(int, int);
	int add();
	~easyProblem();
};

easyProblem::easyProblem(int a, int b)
{
	this -> a = a;
	this -> b = b;
}

int easyProblem::add()
{
	return a + b;
}

easyProblem::~easyProblem()
{
	
}

int main()
{
    int a, b;
    cin>>a>>b; // 输入两个整数 

    easyProblem easy(a,b); // 定义一个easyProblem类型的对象 
    cout<<easy.add();  // 调用easyProblem类的add成员函数计算a+b，之后输出 

    return 0;
}
