#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
struct node
{
	int x1, x2, weight;
};

node a[N];
int pre[N];

bool cmp(node a, node b)
{
	return a.weight < b.weight;
}

int find(int x)
{
	if(x == pre[x])
		return x;
	return pre[x] = find(pre[x]);
}

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		int cost = 0;
		int cnt = 0;
		for(int i = 0; i < n; i++)
			cin >> a[i].x1 >> a[i].x2 >> a[i].weight;
		for(int i = 1; i <= m; i++)
			pre[i] = i;
			
		//根据连通图的定义判边 
		if(n < m - 1)
		{
			cout << "-1" << endl;
			continue;
		}	
		
		sort(a, a + n, cmp);
		
		//并查集模板 
		for(int i = 0; i < n; i++)
		{
			int xx = find(a[i].x1);
			int yy = find(a[i].x2);
			if(xx != yy)
			{
				pre[xx] = yy;
				cost += a[i].weight;
			}
		}
		
		//并查集结果的数量合法性 
		for(int i = 1; i <= m; i++)
		{
			if(i == pre[i])
				cnt++;
		}
		if(cnt == 1)
			cout << cost << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}
