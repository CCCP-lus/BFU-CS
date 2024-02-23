#include<bits/stdc++.h>
using namespace std;

struct node
{
	int next;
	int w;
};

node p, q;
vector<node>g[1001];		//图G 
bool visit[1001] = {false};
int d[1001] = {0x3f3f3f3f};	//最短路长度 
int pre[1001];				//前驱 

void dijkstra(int s, int n)
{
	memset(visit, false, sizeof(visit));
	memset(d, 0x3f3f3f3f, sizeof(d));
	
	//INI 
	for(int i = 1; i <= n; i++)
		pre[i] = i;
	d[s] = 0;
	
	//参考了李冬梅老师的《数据结构》 
	for(int i = 1; i <= n; i++)
	{
		int MIN = 0x3f3f3f3f;
		int k = -1;
		for(int j = 1; j <= n; j++)
		{
			if(!visit[j] && d[j] < MIN)
			{
				k = j;
				MIN = d[j];
			}
		}
		if(k == -1)
			return ;
		visit[k] = true;
		for(int j = 0; j < (int)g[k].size(); j++)
		{
			int h = g[k][j].next;
			if(!visit[h] && (d[k] + g[k][j].w < d[h] || (d[k] + g[k][j].w == d[h] && k < pre[h])))
			{
				d[h] = d[k] + g[k][j].w;
				pre[h] = k;
			}
		}
	}		
}

int main()
{
	int n, m, start, end;
	while(cin >> n >> m >> start >> end)
	{
		for(int i = 0; i < 1001; i++)
			g[i].clear();
		
		//输入边 
		while(m--)
		{
			int x, y, weight;
			cin >> x >> y >> weight;
			//一定要建两条边 
			p.next = y;
			p.w = weight;
			q.next = x;
			q.w = weight;
			g[x].push_back(p);
			g[y].push_back(q);
		}
		
		dijkstra(start, n);
		
		if(d[end] != 0x3f3f3f3f)
			cout << d[end] << endl;
		else 
			cout << "-1" << endl;
	}
	return 0;
}
