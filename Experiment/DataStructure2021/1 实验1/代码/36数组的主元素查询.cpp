#include <iostream>
using namespace std;
int MainElement(int a[],int n)
{//求整数序列a的主元素
	bool flag = false;
	int b[n] = {0};
	for(int i = 0; i < n; i++)
		b[a[i]]++;
	int num, sum = -1;
	for(int i = 0; i < n; i++)
	{
		if(b[i] > sum)
		{
			num = i;
			sum = b[i];
		}
	}
	if(b[num] > n / 2) flag = true;
	if(!flag) return -1;
	else return num;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int *a=new int[n];
        for(int i=0;i<n;i++)  //输入数据
        {
            cin>>a[i];
        }
        cout<<MainElement(a,n)<<endl;   //输出主元素的值
    }
    return 0;
}
