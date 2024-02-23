#include<bits/stdc++.h>
using namespace std;
/**
5
71 24 95 56 54
85 50 74 94 28
92 96 23 71 10
23 61 31 30 46
64 33 32 95 89
6
78 78 11 55 20 11
98 54 81 43 39 97
12 15 79 99 58 10
13 79 83 65 34 17
85 59 61 12 58 97
40 63 97 85 66 90
7
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
15
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
int len=0;
const int an=330000;
vector<int> nex[330000];
vector<int> A;
int m[30][30];
int calc(int row,int mask)
{
    int res=0;
    for(int i=0;i<20;i++){
        if((1<<i)&mask){
            res+=m[row][i];
        }
    }
    return res;
}
int dfs(int r,int c)
{
    int sum=0;
    if(r==len)return sum;
    for(int i=0;i<nex[c].size();i++){
        // calc(r,i);
        sum=max(sum,calc(r,nex[c][i])+dfs(r+1,nex[c][i]));
    }
    return sum;
}

int main()
{
    while(cin>>len)
    {
    	for(int i=0;i<1<<len;i++)
		{
        	if(i&(i<<1))continue;
        	A.push_back(i);
    	}
    	for(int i=0;i<A.size();i++)
		{
        	for(int j=i;j<A.size();j++)
			{
        	    if((A[j]&A[i])||((A[i]<<1)&A[j])||(A[j]<<1)&A[i])
				{
            	    continue;
            	}
                nex[A[i]].push_back(A[j]);
                nex[A[j]].push_back(A[i]);
                // cout<<"A"<<i<<' '<<"push"<<A[j];
        	}
    	}
    	for(int i=0;i<len;i++)
		{
        	for(int j=0;j<len;j++)
        	{
            	cin>>m[i][j];
        	}
    	}
    	cout<<dfs(0,0)<<endl;
    // cout<<"hello"<<endl;
    }
    return 0;
}
