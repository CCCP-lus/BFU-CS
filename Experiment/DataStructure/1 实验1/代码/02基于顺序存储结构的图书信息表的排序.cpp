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
    char name[60];   //ͼ������
    float price;   //ͼ��۸�
}Book;
typedef struct
{//ͼ����˳��洢�ṹ����ΪSqList
    Book *elem;                   //�洢�ռ�Ļ���ַ
    int length;                   //ͼ����е�ǰͼ�����
}SqList;

int BubbleSort_Sq(SqList L)
{//ͼ��˳����ռ۸���ð������
    if(L.length == 0)
    	return ERROR;
	for(int i = 0; i < L.length; i++)
        for(int j = 0; j < L.length - i + 1; j++)
        {
            Book t;
            if(L.elem[j].price < L.elem[j + 1].price)
            {
                t = L.elem[j + 1];
                L.elem[j + 1] = L.elem[j];
                L.elem[j] = t;
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
    for (int i=0;i<MAXSIZE;i++)
    {
        cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].price;
        if(strcmp(L.elem[i].no,"0")==0&&strcmp(L.elem[i].name,"0")==0&&L.elem[i].price==0)
            return OK;            //�������
        else
            L.length++;           //�Ϸ�����ʱ��ͼ�����+1
    }
    return OK;
}

int main()
{
    SqList L;                   //����һ��SqList���͵ı���L
    InitList_Sq(L);             //��ʼ��һ���յ�˳���L
    Input_Sq(L);
    BubbleSort_Sq(L);     //���ռ۸�������
    for(int i=0;i<L.length;i++)  //ͼ�����Ϣ����š��������۸�
        cout<<L.elem[i].no<<" "<< L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;    //�������
    return 0;
}
