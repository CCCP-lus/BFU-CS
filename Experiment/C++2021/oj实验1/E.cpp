#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
int gcd(int m,int n)
{
	while(n^=m^=n^=m%=n);
	return m;
}
 
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
	if(m<n)
	{
		int temp = m;
		m = n;
		n = temp;
	}
	int t=gcd(m,n);
	if(t==1)
		printf("Yes\n");
	else
		printf("No\n");
	}
	return 0;
 
}
