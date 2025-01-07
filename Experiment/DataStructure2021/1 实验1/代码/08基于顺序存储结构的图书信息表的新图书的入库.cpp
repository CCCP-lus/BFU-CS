#include<iostream>
#include <string.h>
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

int Insert_Sq(SqList &L)
{//��ͼ����������
    if(L.length == 0) return ERROR;
    int loc; cin >> loc;
    if(loc < 1 || loc > L.length + 1)
    	cout << "Sorry��the position to be inserted is invalid!" << endl;
    else
    {
		for(int i = L.length - 1; i >= loc - 1; i--)
		{
			L.elem[i + 1] = L.elem[i];
		}
		cin >> L.elem[loc - 1].no >> L.elem[loc - 1].name >>L.elem[loc - 1].price;
		L.length++;
		for(int i = 0; i < L.length; i++)
		{
			cout << L.elem[i].no << " " << L.elem[i].name << " ";
			printf("%.2f\n", L.elem[i].price);
		}
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
        L.length++;
    }
    return OK;
}

int main()
{
    SqList L;           //����һ��SqList���͵ı���L
    InitList_Sq(L);     //��ʼ��һ���յ�˳���L
    Input_Sq(L);        //��������
    Insert_Sq(L);	//��ͼ����������
    return 0;
}



