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
			//s�������мӺ͵��Ͻ� 
			flag = false;
			cout << "Impossible!" << endl;
			continue;
		}
		if(s % 2 == 0)
		{
			//�Ӻ�Ϊż����ôn��4ȡ���23��ʱ��ز�����
			//����012345��0123456 
			if(n % 4 == 2 || n % 4 == 3)
			{
				flag = false;
				cout << "Impossible!" << endl;
				continue;
			}
		}
		else
		{
			//�Ӻ�Ϊ�棬��ôn��4ȡ���01��ʱ��ز�����
			//����0123��01234 
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
			//�Һ޿ո񣡣��� 
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
		return ;	//������һ���������ѭ�� 
	}
	for(int i = 0; i < 2; i++)
	{
		a[c] = a[c - 1] + dirc[i];
		DFS(c + 1, sum + a[c]);
	}
}
