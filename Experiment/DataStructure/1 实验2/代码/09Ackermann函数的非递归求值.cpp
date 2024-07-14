#include<iostream>
using namespace std;
#define MAXSIZE 100
int Ack(int m, int n)
{//Ackermann函数的非递归求值
	int a[100][100];
	for(int i = 0; i < 100; i++)
		a[0][i] = i + 1;
	for(int i = 1; i <= m; i++)
	{
		a[i][0] = a[i - 1][1];
		for(int j = 1; j < 100; j++)
			a[i][j] = a[i - 1][a[i][j - 1]];
	}
	return (a[m][n]);
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
