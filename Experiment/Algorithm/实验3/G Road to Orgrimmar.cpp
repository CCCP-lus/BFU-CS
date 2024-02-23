#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int v;		//终点 
	int w;		//损失血量 
	int next;	//下一条边计数 
}e[100010];

//统计边数 
int num_e;
//记录第一条出边的编号 
int front[10005];

//城市、道路、血量 
int n, m;
long long b;

//经过某点费用
int fee[10005]; 
 
queue<int> q;

//是否在队列 
bool inq[10005];

//与起点的最短路长 
long long d[10005];

inline void AddEdge(int head, int tail, int loss);

//是否满足题意 
bool can(int upc);

int main()
{
	memset(front, -1, sizeof(front));
	cin >> n >> m >> b;
	for(int i = 1; i <= n; i++)
		cin >> fee[i];
	int ea, eb, ec;
	for(int i = 1; i <= m; i++)
	{
		cin >> ea >> eb >> ec;
		AddEdge(ea, eb, ec);
		AddEdge(eb, ea, ec);
	}
	
	//对花费进行排序 
	int temp_fee[10005];
	memcpy(&temp_fee, &fee, sizeof(fee));
	sort(temp_fee + 1, temp_fee + n + 1);
	int l = 1, r = n + 1;
	int mid;
	
	//二分 
	while(l < r)
	{
		mid = (r - l) / 2 + l;
		if(can(temp_fee[mid]))
			r = mid;
		else
			l = mid + 1;
	}
	if(l > r || (l == r && !can(temp_fee[l])))
		cout << "AFK" << endl;
	else	
		cout << temp_fee[l] << endl;
	return 0;
}

inline void AddEdge(int head, int tail, int loss)
{
	num_e++;
	e[num_e].v = tail;
	e[num_e].w = loss;
	e[num_e].next = front[head];
	front[head] = num_e;
}

bool can(int upc)
{
	memset(inq, false, sizeof(inq));
	for(int i = 1; i <= n; i++)
	{
		d[i] = LONG_LONG_MAX;
		//若费用大于upc，加入队列 
		if(fee[i] > upc)
			inq[i] = true;
	}
	if(fee[1] > upc || fee[n] > upc)
		return false;
	else
	{
		//对起点操作 
		d[1] = 0;
		inq[1] = 1;
		q.push(1);
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			inq[u] = false;
			
			//遍历以该点为起点所有边
			for(int i = front[u]; i >= 0; i = e[i].next)
			{
				int tv = e[i].v;
				int tw = e[i].w;
				//更新长度 
				if(d[tv] > d[u] + tw)
				{
					d[tv] = d[u] + tw;
					if(!inq[tv])
					{
						inq[tv] = 1;
						q.push(tv);
					}
				}
			} 
		}
	}
	return d[n] <= b;
}
