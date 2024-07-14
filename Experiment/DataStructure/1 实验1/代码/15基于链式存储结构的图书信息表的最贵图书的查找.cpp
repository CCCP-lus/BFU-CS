#include<iostream>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{//ͼ����Ϣ����
    char no[20];     //ͼ��ISBN
    char name[50];   //ͼ������
    float price;     //ͼ��۸�
}Book;
typedef struct LNode
{//ͼ����Ϣ�����ʽ�洢�ṹ
    Book data;    	   //����������
    int length;       //����ı�����ͼ�����ͼ�����
    struct LNode *next; //ָ����
}LNode,*LinkList;
int HighestPrice_L(LinkList L)
{//���Ҽ۸���ߵ�ͼ��
   LNode* p = L->next;
   float max = -1; int num = 0;
   for(p = L->next; p != NULL; p = p->next)
   {
   		if(p->data.price > max)
   		{
		   	max = p->data.price;
		   	num = 1;
		}
		else if(p->data.price == max)
		{
			num++;
		}
   }
   cout << num << endl;
   for(p = L->next; p != NULL; p = p->next)
   {
		if(p->data.price == max)
		{
			cout << p->data.no << " " << p->data.name << " ";
			printf("%.2f\n", p->data.price);
		}
   }
   return OK;
}

int InitList_L(LinkList &L)
{//����һ���յĵ�����L
    L=new LNode;
    L->next=NULL;
    return OK;
}
int Input_L(LinkList &L)
{//���������
    LinkList p=L;      //��ʼ��pָ�������ͷ���
    int n;
    cin>>n;
    while(n--)             	     //��巨��������
    {
        LinkList q=new LNode;        //�����½��*q
        cin>>q->data.no>>q->data.name>>q->data.price;//��������
        q->next=NULL;                                 //βָ����ΪNULL
        p->next=q;                   //���½��*q����β���*p֮��
        p=q;                         //����ָ��p����pָ���µ�β���*q
    }
    return OK;
}

int main() {
    LinkList L;                      //����һ��LinkList���͵ı���L
    InitList_L(L);                   //��ʼ��һ���յ�����L
    Input_L(L);                      //������������
    HighestPrice_L(L);               //���Ҽ۸���ߵ�ͼ�鲢��������Ϣ
    return 0;
}


