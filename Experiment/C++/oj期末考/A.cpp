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
    cin>>a>>b; // ������������ 

    easyProblem easy(a,b); // ����һ��easyProblem���͵Ķ��� 
    cout<<easy.add();  // ����easyProblem���add��Ա��������a+b��֮����� 

    return 0;
}
