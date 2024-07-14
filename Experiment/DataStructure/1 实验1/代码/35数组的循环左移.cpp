 #include <iostream>
using namespace std;
void Reverse(int R[],int left,int right)
{//������R�е�����ԭ������
	for(int i = left, j = right; i < j; i++, j--)
	{
		int t;
		t = R[i];
		R[i] = R[j];
		R[j] = t;
	}
}
void LeftShift(int R[],int n,int p)
{//������Ϊn������R�е�����ѭ������p��λ��
	Reverse(R, 0, p - 1);
	Reverse(R, p, n - 1);
	Reverse(R, 0, n - 1);
}
void PrintA(int R[],int n)
{//������������е�����
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
        for(int i=0;i<n;i++)  //��������
        {
            cin>>R[i];
        }
        int p;          //p����R�е�����ѭ������p��λ��
        cin>>p;
        LeftShift(R,n,p);         //�����ѭ������
        PrintA(R,n);            //�������
    }
    return 0;
}


