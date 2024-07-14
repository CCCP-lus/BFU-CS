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
int AveRevise_L(LinkList &L)
{//��������ͼ���ƽ���۸��޸ļ۸�
    if(L->length == 0) return ERROR;
	LNode* p;
	double num = 0, sum = 0;
	double ave;
    for(p = L->next; p != NULL; p = p->next)
	{
		sum += p->data.price;
		num++;
	}
	ave = sum / num;
	printf("%.2f\n", ave);
	for(p = L->next; p != NULL; p = p->next)
	{
		if(p->data.price < ave)
			p->data.price *= 1.2;
		else 
			p->data.price *= 1.1;
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
        if(strcmp(no,"0")==0&&strcmp(name,"0")==0&&price==0)
            break;   //���������־
        else
        {//��巨����������
            LinkList q=new LNode;       //�����½��*q
            strcpy(q->data.no, no);      //�����*q��no������Ϊno
            strcpy(q->data.name, name);  //�����*q��name������Ϊname
            q->data.price=price;        //�����*q��price������Ϊprice
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
        p=p->next;                //����pָ�룬ָ����һ�����
    }
    return OK;
}
int Output_L(LinkList L)
{//��������
    LinkList p=L;		//��ʼ��pָ�������ͷ���
    while(p->next)  //��һ��������ʱ
    {
        cout<<p->next->data.no<<" "<<p->next->data.name<<" "<<fixed<<setprecision(2)<<p->next->data.price<<endl;
        p=p->next;   //����pָ�룬ָ����һ�����
    }
    return OK;
}

int main(int argc, const char * argv[]) {
    LinkList L;       		//����һ��LinkList���͵ı���L
    InitList_L(L);              //��ʼ��һ���յ�����L
    Input_L(L);                 //������������
    Length_L(L);              	//������L�ı�L->length
    AveRevise_L(L);            //��������ͼ���ƽ���۸��޸ļ۸�
    Output_L(L);              	//�������L
    return 0;
}
