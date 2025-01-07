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

int RevisePrice_Sq(SqList &L)
{//�޸ļ۸�
    if(L.length == 0)
    	return ERROR;
    double sum = 0;
    for(int i = 0; i < L.length; i++)
    	sum += L.elem[i].price;
    double ave = sum / L.length;
    printf("%.2f\n", ave);
    for(int i = 0; i < L.length; i++)
    {
		if(L.elem[i].price < ave)
			L.elem[i].price *= 1.2;
		else
			L.elem[i].price *= 1.1;
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

int Output_Sq(SqList L)
{//˳�������
    for(int i=0;i<L.length;i++) //ͼ�����Ϣ����š��������۸�
        cout<<L.elem[i].no<<" "<< L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;
    return OK;
}

int main()
{
    SqList L;           //����һ��SqList���͵ı���L
    InitList_Sq(L);     //��ʼ��һ���յ�˳���L
    Input_Sq(L);        //��������
    RevisePrice_Sq(L);    //�޸ļ۸�
    Output_Sq(L);       //�������
    return 0;
}
