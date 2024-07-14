#include<iostream>
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
int Delete_L(LinkList &L)
{//�����ͼ�鲢���
	int loc; cin >> loc;
	if(loc < 1 || loc > L->length)
		cout << "Sorry��the position to be deleted is invalid!" << endl;
	else
	{
		LNode* p = L->next;
		for(int i = 1; i < loc - 1; i++)
			p = p->next;
		LNode* t = p->next;
		p->next = t->next;
		t->next = NULL;
		L->length--;
		delete t;
		LNode*i = L->next;
		while(i)
		{
			cout << i->data.no << " " << i->data.name << " ";
			printf("%.2f\n", i->data.price);			
			i = i->next;
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

int main()
{
    LinkList L;                         //����һ��LinkList���͵ı���L
    InitList_L(L);                      //��ʼ��һ���յ�����L
    Input_L(L);                         //������������
    Length_L(L);                        //������ı�
    Delete_L(L);                        //�����ͼ�鲢���
    return 0;
}
