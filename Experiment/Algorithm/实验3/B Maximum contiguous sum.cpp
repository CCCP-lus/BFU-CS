#include<bits/stdc++.h>
using namespace std;

long long a[100005];
long long mcsum[100005];

int main()
{
	int times;
	cin >> times;
	while(times--)
	{
		memset(a, 0, sizeof(a));
		memset(mcsum, 0, sizeof(mcsum));
		long long n;
		cin >> n;
		for(long long int i = 0; i < n; i++)
		{
			cin >> a[i];
//			mcsum[i - 1] = a[i] + mcsum[i - 1];
		}
		mcsum[0] = a[0];
		//�ݴ����ǰ׺�� 
		long long n_max = mcsum[0];
		for(long long int i = 1; i < n; i++)
		{
			//��ǰ׺�ʹ���0����� 
			if(mcsum[i - 1] >= 0)
				mcsum[i] = mcsum[i - 1] + a[i];
			//�������¿�ʼ���� 
			else
				mcsum[i] = a[i];
			if(mcsum[i] > n_max)
				n_max = mcsum[i];
		}
		cout << n_max << endl;
	}
	return 0;
}
