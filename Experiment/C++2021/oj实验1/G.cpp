#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	
	int count=1;
	int a[8][8];
	int i,j,t=0;
	while(count<=n*n)
	{
		for(i=n-1-t,j=0+t;j<n-1-t;j++)
			a[j][i] = count++;
		if(count>=n*n) break;
		for(i=n-1-t,j=n-1-t;i>0+t;i--)
			a[j][i] = count++;
		if(count>=n*n) break;
		for(i=0+t,j=n-1-t;j>0+t;j--)
			a[j][i] = count++;
		if(count>=n*n) break;
		for(i=0+t,j=0+t;i<n-1-t;i++)
			a[j][i] = count++; 
		if(count>=n*n) break;
		t++;
	}
 
	a[(n-1)/2][(n-1)/2] = n*n;
	int x,y;
	for(x = 0; x < n; x++)
  {
     for(y = 0; y < n; y++)
     {
	 if(y!=n-1)
        printf("%d ", a[x][y]);
     else
     	printf("%d", a[x][y]);
     }
     printf("\n");
  }
}
	return 0;
 }
