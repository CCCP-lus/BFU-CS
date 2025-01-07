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
int InitList_Sq(SqList &L)
{//����һ���յ�˳���L
    L.elem = new Book[MAXSIZE];
    L.length = 0;
    if(L.elem) return OK;
    else return ERROR;
}
int Input_Sq(SqList &L)
{//˳��������
    bool flag = true;
    char a[20], b[20];
	double c;
    while(flag)
    {
        cin >> a >> b >> c;
		if (strcmp(a, "0") == 0 && strcmp(b, "0") == 0 && c == 0)
		{
			flag = false;
			break;
		}
		Book t;
        strcpy(t.no, a);
        strcpy(t.name, b);
        t.price = c;
		L.elem[L.length] = t;
		L.length++;
    }
    return OK;
}
int Output_Sq(SqList L)
{//˳�������
    	cout << L.length << endl;
    for(int i = 0; i < L.length; i++)
    {    
        cout << L.elem[i].no << " " << L.elem[i].name << " ";
        printf("%.2f\n", L.elem[i].price);
    }
	return OK;
}

int main()
{
    SqList L;                   //����һ��SqList���͵ı���L
    InitList_Sq(L);             //��ʼ��һ���յ�˳���L
    Input_Sq(L);                //��������
    Output_Sq(L);               //�������
    return 0;
}
