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
int Input_L(LinkList &L)
{//���������
    int n; cin >> n;
    LNode* p = L;
	for(int i = 0; i < n; i++)
	{
		LNode* t = new LNode;
		t->next = NULL;
		cin >> t->data.no >> t->data.name >> t->data.price;
		p->next = t;
		p = t;
	}
	p = L;
	LNode* cur = NULL;
    LNode* nxt = NULL;
    cur = p->next->next;
    p->next->next = NULL;
    while(cur != NULL)
    {
		nxt = cur->next;
		cur->next = p->next;
		p->next = cur;
		cur = nxt;
	}
    return OK;
}

int InitList_L(LinkList &L)
{//����һ���յĵ�����L
    L=new LNode;
    L->next=NULL;
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

int main(int argc, const char * argv[]) {
    LinkList L;                       //����һ��LinkList���͵ı���L
    InitList_L(L);                    //��ʼ��һ���յ�����L
    Input_L(L);                       //ǰ�巨��������
    Output_L(L);                      //�������L����
    return 0;
}
