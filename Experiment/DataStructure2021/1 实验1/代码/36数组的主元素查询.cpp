#include <iostream>
using namespace std;
int MainElement(int a[],int n)
{//����������a����Ԫ��
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
        for(int i=0;i<n;i++)  //��������
        {
            cin>>a[i];
        }
        cout<<MainElement(a,n)<<endl;   //�����Ԫ�ص�ֵ
    }
    return 0;
}
