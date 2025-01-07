#include<iostream>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000                                  //ͼ�����ܴﵽ����󳤶�
using namespace std;
typedef struct
{//ͼ����Ϣ����
    char no[20];                                        //ͼ��ISBN
    char name[60];                                     //ͼ������
    float price;                                       //ͼ��۸�
}Book;
typedef struct
{//ͼ����˳��洢�ṹ����ΪSqList
    Book *elem;                                         //�洢�ռ�Ļ���ַ
    int length;                                        //ͼ����е�ǰͼ�����
}SqList;

int Input_Sq(SqList &L)
{//˳��������
    int num; cin >> num;
    if(L.length) return ERROR;
    for(int i = 0; i < num; i++)
   	{
        cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
        L.length++;
    }
    Book t;
    for(int i = 0; i < L.length / 2; i++)
    {
   		
   		t = L.elem[i];
   		L.elem[i] = L.elem[L.length - i - 1];
   		L.elem[L.length - i - 1] = t;
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

int Output_Sq(SqList L)
{//˳�������
    for(int i=0;i<L.length;i++) //ͼ�����Ϣ����š��������۸�
        cout<<L.elem[i].no<<" "<< L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;
    return OK;
}

int main()
{
    SqList L;                                           //����һ��SqList���͵ı���L
    InitList_Sq(L);                                    //��ʼ��һ���յ�˳���L
    Input_Sq(L);                                       //����洢��������
    Output_Sq(L);                                      //�������
    return 0;
} 
