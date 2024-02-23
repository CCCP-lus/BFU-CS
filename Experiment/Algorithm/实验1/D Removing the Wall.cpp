#include<bits/stdc++.h>
using namespace std;

//初始化数组并计算前缀和 
void Prefix_Sum(int a[], int n);

int main()
{
	int n, k;
	while(cin >> n >> k)
	{
		int* sum = new int[n];
		Prefix_Sum(sum, n);
		int min = INT_MAX;
		int j = 1;
		for(int i = k; i <= n; i++)
		{
			if(sum[i] - sum[i - k] < min)
			{
				min = sum[i] - sum[i - k];
				j = i - k + 1;
			}
		}
		cout << j << endl;
		delete[] sum;
	}
	return 0;
}

void Prefix_Sum(int a[], int n)
{
	a[0] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		a[i] += a[i - 1];
}
