#include <iostream>
using namespace std;
int Search_Mid(int A[], int B[], int n)
{//求解两个升序序列的中位数
    int i = 0, j = 0, k;
    for(k = 0; k < n - 1; k++)
    {
		if(A[i] < B[j])
			i++;
		else
			j++;
	}
	return A[i] > B[j]?B[j]:A[i];
}

void Input(int a[],int n)
{//读入序列
    for(int i=0;i<n;i++)
        cin>>a[i];
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int A[n],B[n];
        Input(A,n);
        Input(B,n);
        cout<<Search_Mid(A,B,n)<<endl;
    }
    return 0;
}
