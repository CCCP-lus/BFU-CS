#include<bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];
int n, m;

int Bi(int nums[], int x);

int main()
{
	while(cin >> n >> m)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < m; i++)
			cin >> b[i];
		
		for(int i = 0; i < m - 1; i++)
		{
			//特判：a中所有数字都大于声明的数字 
			if(a[0] > b[i])
				cout << a[0] << " ";
			else
				cout << Bi(a, b[i]) << " ";
		}
		//防止最后输出多余空格 
		if(a[0] > b[m - 1])
			cout << a[0] << endl;
		else
			cout << Bi(a, b[m - 1]) << endl;	
	}
	return 0;
}

int Bi(int nums[], int x)
{
	int l = 0;
	int r = n - 1;
	int m;
	while(l <= r)
	{
		m = (r - l) / 2 + l;	//防止越界
		if(nums[m] > x)
			r = m - 1;
		else if(nums[m] < x)
			l = m + 1;
		else
			return nums[m]; 
	}
	if(nums[m] > x)
		return nums[m - 1];
	else
		return nums[m];
}
