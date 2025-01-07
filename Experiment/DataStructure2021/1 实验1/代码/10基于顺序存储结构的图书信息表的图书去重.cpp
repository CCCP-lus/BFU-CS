#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000    //ͼ�����ܴﵽ����󳤶�
using namespace std;
typedef struct
{//ͼ����Ϣ����
    char no[20];    //ͼ��ISBN
    char name[50];   //ͼ������
    float price;   //ͼ��۸�
}Book;
typedef struct
{//ͼ����˳��洢�ṹ����ΪSqList
    Book *elem;                   //�洢�ռ�Ļ���ַ
    int length;                   //ͼ����е�ǰͼ�����
}SqList;

int SearchList(SqList L,char no[20])
{//��������Ƿ���ͼ����Ϣ��L��
	if(L.length == 0) return ERROR;
	for(int i = 0; i < L.length; i++)
	{
		if(strcmp(no, L.elem[i].no) == 0)
			return OK;
	}
	return ERROR;
}
int DupRemoval_Sq(SqList L1,SqList &L2)
{//ͼ��ȥ��
	int j = 0;
	for(int i = 0; i < L1.length; i++)
	{
		if(!SearchList(L2, L1.elem[i].no))
		{
			L2.length++;
			L2.elem[j] = L1.elem[i];
			j++;
		}
	}
	cout << L2.length << endl;
	for(int i = 0; i < L2.length; i++)
	{
		cout << L2.elem[i].no << " " << L2.elem[i].name << " ";
		printf("%.2f\n", L2.elem[i].price);
	}
	return OK;
}

int InitList_Sq(SqList &L)
{//����һ���յ�˳���L
    L.elem=new Book[MAXSIZE];     //Ϊ˳������һ����СΪMAXSIZE������ռ�
    if(!L.elem)exit(OVERFLOW);    //�洢����ʧ���˳�
    L.length=0;                   //�ձ���Ϊ0
    return OK;
}
int Input_Sq(SqList &L)
{//˳��������
    int n;
    cin>>n;    //ͼ����Ŀn
    for(int i=0;i<n;i++)
    {
        cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].price;
        L.length++;//ͼ�����+1
    }
    return OK;
}
int main() {
    SqList L1,L2;            	 //����SqList���͵ı���L1,L2
    InitList_Sq(L1);        	 //��ʼ��һ���յ�˳���L1
    InitList_Sq(L2);       	 //��ʼ��һ���յ�˳���L2
    Input_Sq(L1);          	 //�������ݵ�L1
    DupRemoval_Sq(L1,L2);       //ͼ��ȥ�ز�������
    return 0;
}
