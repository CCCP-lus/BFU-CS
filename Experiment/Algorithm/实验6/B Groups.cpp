#include<bits/stdc++.h>
using namespace std;

const int maxn = 1050;
int s[maxn];	//sets
int height[maxn];

struct root
{
	int r;		//根节点 
	int num;	//数量 
};
root roots[maxn];

void init_set()
{
	for(int i = 1; i <= maxn; i++)
	{
		s[i] = i;
		height[i] = 0;
		roots[i].r = 0;
		roots[i].num = 0;
	}
}

int find_set(int x)
{
	if(x != s[x])
		s[x] = find_set(s[x]);
	return s[x];
}

void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);
	if(x == y)
		return;
	if(height[x] == height[y])
	{
		height[x] = height[x] + 1;
		s[y] = x;
	}
	else
	{
		if(height[x] < height[y])
			s[x] = y;
		else
			s[y] = x;
	}
}

int main()
{
	int times;
	cin >> times;
	while(times--)
	{
		int n, m, x, y;
		cin >> n >> m;
		init_set();
		for(int i = 1; i <= m; i++)
		{
			cin >> x >> y;
			union_set(x, y);
		}
		int k = 1;
		for(int i = 1; i <= n; i++)
		{
			if(s[i] == i)
			{
				roots[k].r = s[i];
				k++;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j < k; j++)
			{
				if(find_set(s[i]) == roots[j].r)
				{
					roots[j].num++;
					break;
				}
			}
		}
		int minn = INT_MAX;
		for(int i = 1; i < k; i++)
		{
			if(roots[i].num < minn)
				minn = roots[i].num;
		}
		cout << minn << endl;
	}
	return 0;
}
