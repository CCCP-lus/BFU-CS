#include<bits/stdc++.h>
using namespace std;

int a[100005];
double m[100005];
double P[100005];

int main()
{
	int T; cin >> T;
	while(T--)
	{
		memset(a, 0, sizeof(a));
		memset(m, 0, sizeof(m));
		memset(P, 0, sizeof(P));
		
		P[0] = 1;	//�������ӣ�100%��� 
		
		double p; 
		int n;
		cin >> p >> n;
		
		int cnt = 0, maxn = 0;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i] >> m[i];
			cnt += a[i];	//ͳ�ƲƱ��� 
		}
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = cnt; j >= a[i]; j--)
			{
				//���������������ֵ��ֹ 
				//�򿪵�ǰ����ǰ��״̬�͵�ǰ���������֮�� 
				P[j] = max(P[j], P[j - a[i]] * (1 - m[i]));	
			}
		}
		
		for(int i = 1; i <= cnt; i++)
		{
			if(P[i] > 1 - p)
				maxn = i;
		}
		
		cout << maxn << endl;
	}
	return 0;
}
