#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[1000],b[1000];
	int i,m,t=2;
	for(i=0;i<n;i++)
	{
		a[i] = 0;
		b[i] = i+1;
	}
	for(i=0;i<k-1;i++)
	{
		for(m=0;m<n;m++)
		if(b[m]%t==0)
		{
			if(a[m]==1)
				a[m]=0;
			else
				a[m]=1;
		}
		t++;
	}
	for(i=0;i<n;i++)
		if(a[i]!=1)
			printf("%d ",b[i]);
	return 0;
}
