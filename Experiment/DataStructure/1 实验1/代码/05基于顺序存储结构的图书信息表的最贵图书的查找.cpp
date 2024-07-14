#include<iostream>
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

int HighestPrice_Sq(SqList L)
{//���Ҽ۸���ߵ�ͼ�鲢�����Ӧͼ�����Ϣ
    if(L.length == 0) return ERROR;
    float max = -100;
    int num = 0;
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
    for(int i = 0; i < L.length; i++)
    {
		if(L.elem[i].price >= max)
		{
			max = L.elem[i].price;
			num++;
		}
	}
    cout << num << endl;
    for(int i = 0; i < num; i++)
    {
		cout << L.elem[i].no << " " << L.elem[i].name << " ";
		printf("%.2f\n", L.elem[i].price);
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
    SqList L;               //����һ��SqList���͵ı���L
    InitList_Sq(L);         //��ʼ��һ���յ�˳���L
    Input_Sq(L);            //��������
    HighestPrice_Sq(L);     //���Ҽ۸���ߵ�ͼ�鲢�����Ӧͼ�����Ϣ
    return 0;
}
