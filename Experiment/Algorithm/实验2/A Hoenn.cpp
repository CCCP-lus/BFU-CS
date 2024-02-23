#include<bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool visited[1001][1001] = {false};
int num = 1;

void DFS(int i, int j, int n);

int main()
{
	int n;
	while(cin >> n)
	{
		if(n == 0)
			break; 
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				graph[i][j] = ' ';
				visited[i][j] = false;
			}
		int Max = -1;
		for(int i = 1; i <= n; i++)
			cin >> (graph[i] + 1);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(!visited[i][j] && graph[i][j] == 'a')
				{
					num = 1;	//该点所在面积，不能作为DFS的参数否则不加 
					visited[i][j] = true;
					DFS(i, j, n);
					Max = max(Max, num);	
				}
			}
		}
		cout << Max << endl;
	}
	return 0;
}

void DFS(int i, int j, int n)
{
	int x, y;
	int times = 5;
	while(times--)
	{
		switch (times) 
		{
			case 4://向左 
				x = i - 1;
				y = j;
				if(x < 1 || x > n || y < 1 || y > n)
					continue;
				if(!visited[x][y] && graph[x][y] == 'a')
				{
					visited[x][y] = true;
					num++;
					DFS(x, y, n);
				}
				break;
			case 3://向上 
				x = i;
				y = j - 1;
				if(x < 1 || x > n || y < 1 || y > n)
					continue;
				if(!visited[x][y] && graph[x][y] == 'a')
				{
					visited[x][y] = true;
					num++;
					DFS(x, y, n);
				}				
				break;
			case 2://向右 
				x = i + 1;
				y = j;
				if(x < 1 || x > n || y < 1 || y > n)
					continue;
				if(!visited[x][y] && graph[x][y] == 'a')
				{
					visited[x][y] = true;
					num++;
					DFS(x, y, n);
				}				
				break;
			case 1://向下 
				x = i;
				y = j + 1;
				if(x < 1 || x > n || y < 1 || y > n)
					continue;
				if(!visited[x][y] && graph[x][y] == 'a')
				{
					visited[x][y] = true;
					num++;
					DFS(x, y, n);
				}
				break;
			default:
				break;
		}
	}
		
}
