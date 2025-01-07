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

int FindLocate_Sq(SqList L)
{//�������λ��ͼ�鲢�������
    if(L.length == 0) return ERROR;
	int num; cin >> num;
    while(num--)
    {
		int loc; cin >> loc;
		if(loc < 1 || loc > L.length)
			cout << "Sorry��the book on the best position doesn't exist!" <<endl;
		else
		{
			int i = loc - 1;
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
    SqList L;            //����һ��SqList���͵ı���L
    InitList_Sq(L);      //��ʼ��һ���յ�˳���L
    Input_Sq(L);         //��������
    FindLocate_Sq(L);    //�������λ��ͼ�鲢�������
    return 0;
}
