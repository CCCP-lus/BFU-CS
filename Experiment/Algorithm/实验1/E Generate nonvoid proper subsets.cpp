#include<bits/stdc++.h>
using namespace std;

//深度优先搜索选数 
void GNPS(int x, int y, int n, int a[], int b[]);

int main()
{
	int n;
	while(cin >> n)
	{
		int *a = new int[20];
		int *b = new int[20];
		for(int i = 0; i < (int)sizeof(a); i++)
		{
			a[i] = b[i] = 0;
		}
		
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		
		sort(a + 1, a + n + 1);
		
		for(int i = 1; i < n; i++)
			GNPS(1, i, n, a, b);
			
		cout << endl;
		
		delete[] a;
		delete[] b;
	}
	return 0;
}

void GNPS(int x, int y, int n, int a[], int b[])
{
	if(y + 1 == x)
	{
		for(int i = 1; i < x; i++)
			cout << b[i];
		cout <<endl;
		return ;
	}
	for(int i = x; i <= n; i++)
	{
		bool flag = true;
		for(int j = 1; j < x; j++)
			if(b[j] >= a[i])
				flag = false;
		if(flag)
		{
			b[x] = a[i];
			GNPS(x + 1, y, n, a, b);
		}
	}
}
