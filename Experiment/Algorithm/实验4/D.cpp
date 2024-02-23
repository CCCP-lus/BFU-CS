#include<bits/stdc++.h>
using namespace std;

int M[100005];
double P[100005];
double V[100005];

int main()
{
	int T; cin >> T;
	while(T--)	
	{
		memset(M, 0, sizeof(M));
		memset(P, 0, sizeof(P));
		memset(V, 0, sizeof(V));
		
		double p; 
		int n;
		cin >> p >> n;
		int cnt = 0, maxn = 0;
		
		//默认的输出结果是1 
		V[0] = 1;
		
		for(int i = 1; i <= n; i++)	
		{
			cin >> M[i] >> P[i];
			cnt += M[i];
		}	
		for(int i = 1; i <= n; i++)
		{
			for(int j = cnt; j >= M[i]; j--)
				if(V[j] < V[j - M[i]] * (1 - P[i]))
					V[j] = V[j - M[i]] * (1 - P[i]);
					
		}
		
		for(int i = 1; i <= cnt; i++)
			if(V[i] > 1 - p)
				maxn = i;
		cout << maxn << endl;
	}
	
	return 0;
}
