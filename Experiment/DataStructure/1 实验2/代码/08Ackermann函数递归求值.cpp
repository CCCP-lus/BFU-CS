#include<iostream>
using namespace std;
int Ack(int m, int n)
{//Ackermann函数的递归求值
	if(m == 0)
		return n + 1;
	else if(m > 0 && n == 0)
		return Ack(m - 1, 1);
	else
		return Ack(m - 1, Ack(m, n - 1));
}

int main()
{
	int m,n;
	while(cin>>m>>n)
    {
        if(m==0&&n==0) break;
        cout<<Ack(m,n)<<endl;
    }
	return 0;
}
