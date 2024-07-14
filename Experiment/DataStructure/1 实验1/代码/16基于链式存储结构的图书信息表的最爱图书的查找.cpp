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
int FindFavorite_L(LinkList &L)
{//���ҵ��ͼ�鲢�������
//	if(L->length == 0) return ERROR;
	int n; cin >>n;
	while(n--)
	{
		char c[50]; cin >> c;
		int num = 0;
		for(LNode*p = L->next; p != NULL; p = p->next)
			if(strcmp(p->data.name, c) == 0)
				num++;
		if(num == 0) cout << "Sorry��there is no your favourite!" << endl;
		else cout << num << endl;
		for(LNode*p = L->next; p != NULL; p = p->next)
			if(strcmp(p->data.name, c) == 0)
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
int main()
{
    LinkList L;                         //����һ��LinkList���͵ı���L
    InitList_L(L);                    	//��ʼ��һ���յ�����L
    Input_L(L);                        	//������������
    FindFavorite_L(L);                	//���ҵ��ͼ�鲢�������
    return 0;
}
