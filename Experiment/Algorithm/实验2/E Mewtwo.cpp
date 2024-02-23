//#include<bits/stdc++.h>
//using namespace std;
//
//char graph[1001][1001];//地图 
//bool visited[1001][1001] = {false};//访问情况 
//int Min = INT_MAX;
//int mx = 0, my = 0, dx = 0, dy = 0; 
//
//int pace = 1;
//bool result = false;
//
//int newx[4] = {0, 1, -1, 0};
//int newy[4] = {1, 0, 0, -1};
//
//void trace(int x, int y, int n);
//
//int main()
//{
//	int n;
//	while(cin >> n)
//	{
//		pace = 0;
//		Min = INT_MAX;
//		result = false;
//		if(n == 0)
//			break;
//		for(int i = 1; i <= n; i++)
//		{
//			cin >> (graph[i] + 1);
//			for(int j = 1; j <= n; j++)
//			{
//				visited[i][j] = false;
//				if(graph[i][j] == 'M')
//				{
//					mx = i;
//					my = j;
//				}
//				if(graph[i][j] == 'D')
//				{
//					dx = i;
//					dy = j;
//				}
//			}
//		}
//			
//		trace(mx, my, n);
//		
//		if(result)	
//			cout << Min << endl;
//		else
//			cout << -1 << endl;
//	}
//	return 0;
//}
//
//void trace(int x, int y, int n)
//{
//	if(x == dx && y == dy)
//	{
//		//把此路径和已知最短路比较 
//		result = true;
//		Min = Min > pace? pace: Min;
//		return ;
//	}
//	else
//	{
//		for(int i = 0; i < 4; i++)
//		{
//			//判出界 
//			if(x + newx[i] < 1 || x + newx[i] > n || y + newy[i] < 1 || y + newy[i] > n)
//				continue;
//			//四个方位依次搜索，保存路径 
//			if(!visited[x + newx[i]][y + newy[i]] && (graph[x + newx[i]][y + newy[i]] == '@' || graph[x + newx[i]][y + newy[i]] == 'D'))
//			{
//				visited[x][y] = true;
//				cout << x + newx[i] << " " << y + newy[i] << endl;
//				pace++;
//				trace(x + newx[i], y + newy[i], n);
//				visited[x][y] = false;
//				pace--;
//			}
//		}
//	}
//}
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x, y;
};

int newx[4] = {0, 1, -1, 0};
int newy[4] = {1, 0, 0, -1};

char graph[1001][1001];//地图 
int visited[1001][1001] = {false};//访问情况 

int BFS(queue<node>q, int ex, int ey, int n)
{
	while(!q.empty())
	{
		node p = q.front();
		q.pop();
		if(p.x == ex && p.y == ey)
			break;
		else
		{
			for(int i = 0; i < 4; i++)
			{
				int x0 = p.x + newx[i];
				int y0 = p.y + newy[i];
				if(x0 > 0 && x0 <= n && y0 > 0 && y0 <= n && graph[x0][y0] != '#' && visited[x0][y0] == INT_MAX)
				{
					node temp;
					temp.x = x0;
					temp.y = y0;
					q.push(temp);
					visited[x0][y0] = visited[p.x][p.y] + 1;
				}
			}
		}
	}
	if(visited[ex][ey] != INT_MAX)
		return visited[ex][ey];
	else
		return -1;
}

int main()
{
	int n;
	while(cin >> n)
	{
		if(n == 0)
			break;
		queue<node> q;
		int sx, sy;
		int ex, ey;
		for(int i = 1; i <= n; i++)
		{
			cin >> (graph[i] + 1);
			for(int j = 1; j <= n; j++)
			{
				visited[i][j] = INT_MAX;
				if(graph[i][j] == 'M')
				{
					sx = i;
					sy = j;
					visited[i][j] = 0;
				}
				if(graph[i][j] == 'D')
				{
					ex = i;
					ey = j;
				}
			}
		}
		node p = {sx, sy};
		q.push(p);
		cout << BFS(q, ex, ey, n) << endl;	
	}
	
	return 0;
}
