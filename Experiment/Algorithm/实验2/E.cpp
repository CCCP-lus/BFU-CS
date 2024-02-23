#include<bits/stdc++.h>
using namespace std;

void DFS(int c, int sum);
int a[35] = {0};
bool flag = true;	
int n, s;
int dirc[] = {-1, 1};

int main()
{
	flag = true;
	for(int i = 0; i < 35; i++)
		a[i] = 0;
	while(cin >> n >> s)
	{
		if(s > 0.5 * n * (n - 1))
		{
			//s超出队列加和的上界 
			flag = false;
			cout << "Impossible!" << endl;
			continue;
		}
		if(s % 2 == 0)
		{
			//加和为偶，那么n对4取余得23的时候必不成立
			//比如012345和0123456 
			if(n % 4 == 2 || n % 4 == 3)
			{
				flag = false;
				cout << "Impossible!" << endl;
				continue;
			}
		}
		else
		{
			//加和为奇，那么n对4取余得01的时候必不成立
			//比如0123和01234 
			if(n % 4 == 0 || n % 4 == 1)
			{
				flag = false;
				cout << "Impossible!" << endl;
				continue;
			}			
		}
//		DFS(1, 0);
		DFS(2, 0);
		if(!flag) 
		{
			cout << "Impossible!" << endl;
			continue;
		}
	}
	return 0;
}

void DFS(int c, int sum)
{
	if(c == n + 1)
	{
		if(sum == s)
		{
			flag = true;
			//我恨空格！！！ 
//			for(int i = 1; i <= n; i++)
//				cout << a[i] << " ";
//			cout << a[1];
//			for(int i = 2; i <= n; i++)
//				cout << " " << a[i];
			for(int i = 1; i <= n; i++)
			{
				cout << a[i];
				if(i != n)
					cout << " ";
			}
			cout << endl;
		}
		return ;	//不加这一步会出现死循环 
	}
	for(int i = 0; i < 2; i++)
	{
		a[c] = a[c - 1] + dirc[i];
		DFS(c + 1, sum + a[c]);
	}
}
