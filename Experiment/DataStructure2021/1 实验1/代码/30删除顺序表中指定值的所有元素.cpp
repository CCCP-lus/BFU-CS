#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct {
    int* elem;       //�洢�ռ�Ļ���ַ
    int length;      //��ǰ����
}SqList;
void InitList_Sq(SqList& L, int n) 
{
    //����˳���
	L.elem = new int[MAXSIZE];
	L.length = n;
}
void DeleteItem(SqList& A, int item) 
{
    //ɾ��˳���A������ֵΪitem��Ԫ��
	for(int i = 0; i < A.length; i++)
	{
		while(A.elem[i] == item)
		{
			for(int j = i; j < A.length; j++)
				A.elem[j] = A.elem[j + 1];
			A.length--;
		}	
	}
}

void PrintA(SqList A)
{//�������Ԫ��
    for(int i=0;i<A.length-1;i++)
        cout<<A.elem[i]<<" ";
    cout<<A.elem[A.length-1]<<endl;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        SqList A;
        InitList_Sq(A,n);
        for(int i=0;i<n;i++)
            cin>>A.elem[i];
        int item;
        cin>>item;
        DeleteItem(A,item);
        PrintA(A);
    }
    return 0;
}
