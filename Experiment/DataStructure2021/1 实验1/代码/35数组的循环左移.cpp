 #include <iostream>
using namespace std;
void Reverse(int R[],int left,int right)
{//将数组R中的数据原地逆置
	for(int i = left, j = right; i < j; i++, j--)
	{
		int t;
		t = R[i];
		R[i] = R[j];
		R[j] = t;
	}
}
void LeftShift(int R[],int n,int p)
{//将长度为n的数组R中的数据循环左移p个位置
	Reverse(R, 0, p - 1);
	Reverse(R, p, n - 1);
	Reverse(R, 0, n - 1);
}
void PrintA(int R[],int n)
{//依次输出数组中的数据
	for(int i = 0; i < n; i++)
	{
		cout << R[i];
		if(i != n - 1)
			cout << " ";
	}
	cout << endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int *R = new int[n];
        for(int i=0;i<n;i++)  //输入数据
        {
            cin>>R[i];
        }
        int p;          //p代表将R中的序列循环左移p个位置
        cin>>p;
        LeftShift(R,n,p);         //数组的循环左移
        PrintA(R,n);            //输出数据
    }
    return 0;
}


