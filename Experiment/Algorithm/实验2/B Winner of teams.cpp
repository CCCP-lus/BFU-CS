#include<bits/stdc++.h>
using namespace std;

int teams[501][501];
int defeated[501];
int arr[501];

void topological_sorting(int n);

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		memset(teams, 0, sizeof(teams));
		memset(arr, 0, sizeof(arr));
		memset(defeated, 0, sizeof(defeated));
		while(m--)
		{
			int x, y;
			cin >> x >> y;
			teams[x][y] = 1;
			defeated[y]++;
		}
		topological_sorting(n);
	}
	return 0;
}

void topological_sorting(int n)
{
	int arr_t = 0;
	for(int i = 1; i <= n; i++)
	{
		int r = 1;
		//找到第一个无入度节点 
		while(defeated[r] != 0)
			r++;
		arr[arr_t] = r;
		arr_t++;
		defeated[r] = -1;
		for(int j = 1; j <= n; j++)
			if(teams[r][j] == 1)
				defeated[j]--;
	}
	for(int i = 0; i < n - 1; i++)
		cout << arr[i] << " ";
	cout << arr[n - 1] << endl;
}
