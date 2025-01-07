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

int Sort_L(LinkList &L)
{//��ͼ�鰴�ռ۸�������
    LNode *head = L, *p1, *prep1, *p2, *prep2, *temp;
    prep1 = L->next;
    p1 = prep1->next;
    bool flag;
    while(p1)
    {
		flag = true;
		temp = p1;
		for(prep2 = head, p2 = prep2->next; p2 != p1; prep2 = prep2->next, p2 = p2->next)
		{
			if(p2->data.price < p1->data.price)
			{
				p1 = p1->next;
				prep1->next = p1;
				prep2->next = temp;
				temp->next = p2;
				flag = false;
				break;
			}
		}	
		if(flag)
		{
			prep1 = prep1->next;
			p1 = p1->next;
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
    LinkList p=L;    //��ʼ��pָ�������ͷ���
    char no[20];
    char name[50];
    float price;
    while(cin>>no>>name>>price)
    {
        if(strcmp(no,"0")==0&&strcmp(name,"0")==0&&price==0)//���������־
            break;
        else
        {//��巨����������
            LinkList q=new LNode;       //�����½��*q
            strcpy(q->data.no, no);      //�����*q�������no������Ϊno
            strcpy(q->data.name, name);  //�����*q�������name������Ϊname
            q->data.price=price;        //�����*q�������price������Ϊprice
            q->next=NULL;               //βָ����ΪNULL
            p->next=q;                 //���½��*q����β���*p֮��
            p=q;                       //����p����pָ���µ�β���*q
        }
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
    LinkList p=L;		//��ʼ��pָ�������ͷ���
    while(p->next)  //��һ��������ʱ
    {
        cout<<p->next->data.no<<" "<<p->next->data.name<<" "<<fixed<<setprecision(2)<<p->next->data.price<<endl;
        p=p->next;   //����ָ��p��ָ����һ�����
    }
    return OK;
}

int main()
{
    LinkList L;                	//����һ��LinkList���͵ı���L
    InitList_L(L);            	//��ʼ��һ���յ�����L
    Input_L(L);                	//��������
    Length_L(L);            	//��������L�ı�L->length
    Sort_L(L);                	//��������
    Output_L(L);            	//�������
    return 0;
}
