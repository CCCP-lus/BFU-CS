#include<bits/stdc++.h>
using namespace std;

char graph[101][101];
bool visited[101][101] = {false};
int num = 1;

void DFS(int i, int j, int w, int h);

int main()
{
	int w, h;
	while(cin >> w >> h)
	{
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= w; j++)
			{
				graph[i][j] = ' ';
				visited[i][j] = false;
				
			}
		for(int i = 1; i <= h; i++)
			cin >> (graph[i] + 1);
		int x = 0, y = 0;
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= w; j++)
				if(graph[i][j] == 'G')
				{
					num = 1;
					x = i;
					y = j;
					visited[i][j] = true; 
					break;
				}
		DFS(x, y, w, h);
		cout << num << endl;
	}
	return 0;
}

void DFS(int i, int j, int w, int h)
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
				if(x < 1 || x > h || y < 1 || y > w)
					continue;
				if(!visited[x][y] && graph[x][y] == 'D')
				{
					visited[x][y] = true;
					num++;
					DFS(x, y, w, h);
				}
				break;
			case 3://向上 
				x = i;
				y = j - 1;
				if(x < 1 || x > h || y < 1 || y > w)
					continue;
				if(!visited[x][y] && graph[x][y] == 'D')
				{
					visited[x][y] = true;
					num++;
					DFS(x, y, w, h);
				}				
				break;
			case 2://向右 
				x = i + 1;
				y = j;
				if(x < 1 || x > h || y < 1 || y > w)
					continue;
				if(!visited[x][y] && graph[x][y] == 'D')
				{
					visited[x][y] = true;
					num++;
					DFS(x, y, w, h);
				}				
				break;
			case 1://向下 
				x = i;
				y = j + 1;
				if(x < 1 || x > h || y < 1 || y > w)
					continue;
				if(!visited[x][y] && graph[x][y] == 'D')
				{
					visited[x][y] = true;
					num++;
					DFS(x, y, w, h);
				}
				break;
			default:
				break;
		}
	}	
}
