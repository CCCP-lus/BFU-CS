#include<iostream>
#include<string.h>
using namespace std;

long long a[1000005];
const long long module = 1e9 + 7;

long long find_ways(int n);

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		long long sum = find_ways(--n);	//�Զ���һ�� 
		printf("%lld\n", sum);
	}
	return 0;	
}

long long find_ways(int n)
{
	//����0 
	if(n < 0)
		return 0;
	else if(n == 0)
		return 1;
	//������� 
	else if(n == 1 || n == 2 || n == 3)
		return n;
	else
	{
		memset(a, 0, n + 1);
		//�㿪�ֳԵ�һ�� 
		a[0] = 1; a[1] = 1;
		for(int i = 2; i <= n; i++)
			if(!a[i])
				a[i] = (a[i - 1] + a[i - 2]) % module;
		return a[n];		
	}
}
