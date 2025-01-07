#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
class huiwen
{
	public:
	char a[100];
}store[50];
  
int main()
{
	int n,i,k,cnt=0;
	scanf("%d",&n);
	char temp[100];
	
	for(i=0;i<n;i++)
	{
		int ret = 0;
		int k;
		scanf("%s",temp);
		int left = 0;
		int right = strlen(temp)-1;
		for(;;left++)
		{
		
			if(temp[left]!=temp[right])
				break;
			else
				ret++;
			if(ret==(strlen(temp)/2))
			{
				strcpy(store[cnt].a,temp);
				cnt++;
			}
			if(right%2==0)
				if(right-left==1)
					break;
			if(right%2!=0)
				if(right==left)
					break;
			right--;
		}
	}
 
	for(i=0;i<cnt;i++)
		for(k=0;k<cnt-i-1;k++)
			if(strlen(store[k].a)>strlen(store[k+1].a))
			{
				char s[100];
				strcpy(s,store[k].a);
				strcpy(store[k].a,store[k+1].a);
				strcpy(store[k+1].a,s);
			}
			
	for(i=0;i<cnt;i++)
		puts(store[i].a);
	return 0;
}
