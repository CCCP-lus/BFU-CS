#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{//ͼ����Ϣ����
    char no[20];    //ͼ��ISBN
    char name[50];   //ͼ������
    float price;   //ͼ��۸�
}Book;
typedef struct LNode
{//ͼ����Ϣ�����ʽ�洢�ṹ
    Book data;    	   //����������
    int length;       //����ı�����ͼ�����ͼ�����
    struct LNode *next; //ָ����
}LNode,*LinkList;
int DupRemoval_L(LinkList &L)
{//ͼ��ȥ��
	LNode* p = L->next;
	while(p)
	{
		LNode* q = p;
		while(q->next)
		{
			if(strcmp(q->next->data.no, p->data.no) == 0)
			{
				LNode* t = q->next;
				q->next = q->next->next;
				L->length--;
				delete t;
			}   
			else
				q = q ->next;	
		}
		p = p->next;	
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
int  Length_L(LinkList &L)
{//������ı�����ͼ�����ͼ�����
    LinkList p=L;                 //��ʼ��pָ�������ͷ���
    L->length=0;                  //��ʼ������ı�L->lengthΪ0
    while(p->next)                //��һ��������ʱ
    {
        L->length++;              //����ı�+1
        p=p->next;                //����ָ��p��ָ����һ�����
    }
    return OK;
}
int Output_L(LinkList L)
{//��������
    Length_L(L);
    cout<<L->length<<endl;   //ȥ�غ��ͼ����Ŀ
    LinkList p=L;           //��ʼ��pָ�������ͷ���
    while(p->next)                	//��һ��������ʱ
    {
        cout<<p->next->data.no<<" "<<p->next->data.name<<" "<<fixed<<setprecision(2)<<p->next->data.price<<endl;
        p=p->next;    //����ָ��p��ָ����һ�����
    }
    return OK;
}
int main()
{
    LinkList L;                         //����һ��LinkList���͵ı���L
    InitList_L(L);                      //��ʼ��һ���յ�����L
    Input_L(L);                         //������������
    DupRemoval_L(L);                   //����ɾ��
    Output_L(L);                        //��������
    return 0;
}




