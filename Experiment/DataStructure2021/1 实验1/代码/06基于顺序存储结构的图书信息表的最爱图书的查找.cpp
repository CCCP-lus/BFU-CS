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

int FindFavorite_Sq(SqList L)
{//�ͼ��Ĳ��Ҳ��������
	if(L.length == 0) return ERROR;
	int num; cin >> num;
	while(num)
	{
		bool find = false;
		char b[50];
		cin >> b;
		int n = 0;
		for(int i = 0; i < L.length; i++)
		{
			if(strcmp(b, L.elem[i].name) == 0)
			{
				find = true;
				n++;
			}
		}
		if(n != 0)
			cout << n << endl;
		for(int i = 0; i < L.length; i++)
		{
			if(strcmp(b, L.elem[i].name) == 0)
			{
				cout << L.elem[i].no << " " << L.elem[i].name << " ";
				printf("%.2f\n", L.elem[i].price);
			}
		}
		if(!find)
			cout << "Sorry��there is no your favourite!" << endl;
		num--;
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
    SqList L;              //����һ��SqList���͵ı���L
    InitList_Sq(L);        //��ʼ��һ���յ�˳���L
    Input_Sq(L);           //��������
    FindFavorite_Sq(L);    //�ͼ��Ĳ��Ҳ��������
    return 0;
}
