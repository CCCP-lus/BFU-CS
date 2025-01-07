#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
int main()
{
	int m,n;
	int i,k;
	int cnt[100][100],ret[100][100],t[100][100];
	for(i=0;i<100;i++)
	for(k=0;k<100;k++)
	{	
		cnt[i][k]=0;
		t[i][k]=0;
	}
	scanf("%d%d",&m,&n);
	int a[100][100];
	for(i=0;i<m;i++)
		for(k=0;k<n;k++)
			scanf("%d",&a[i][k]);
	for(i=0;i<m;i++)
	{	
		int temp = 0;
		for(k=0;k<n;k++)
		{
			if(a[i][k]==0)
			{
				cnt[i][temp]++;
			}
			else
			{
				cnt[i][temp]++;
				printf("%d %d %d\n",i+1,cnt[i][temp],a[i][k]);
				temp++;
				cnt[i][temp] = cnt[i][temp-1];
			}
		}
	}
	return 0;
}
