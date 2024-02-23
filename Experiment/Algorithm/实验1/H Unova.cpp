#include<bits/stdc++.h>
using namespace std;

//深度优先搜索 
void DFS(int x, int n, int a[], bool visited[]);

int main()
{
	int n;
	while(cin >> n)
	{
		int *a = new int[11];
		bool *visited = new bool[11];
		for(int i = 0; i < 11; i++)
		{
			a[i] = 0;
			visited[i] = false;
		}
		DFS(1, n, a, visited);
		cout << endl;
		delete[] a;
		delete[] visited;		
	}
	return 0;
}

void DFS(int x, int n, int a[], bool visited[])
{
	if(n + 1 == x)
	{
		for(int i = 1; i <= n; i++)
			cout << a[i];
		cout << endl;
		return ;
	}
	for(int i = 1; i <= n; i++)
		if(!visited[i])
		{
			a[x] = i;
			visited[i] = true;
			DFS(x + 1, n, a, visited);
			visited[i] = false;
		}
}
