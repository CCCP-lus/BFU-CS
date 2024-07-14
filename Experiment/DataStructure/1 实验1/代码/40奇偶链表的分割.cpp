#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//��巨����������
	L = new LNode;
	L->next = NULL;
	int num = n;
	LNode* p = L;
	while(num--)
	{
		LNode* t = new LNode;
		cin >> t->data;
		t->next = NULL;
		p->next = t;
		p = t;
	}
}
void Decollate(LinkList &L, LinkList &L1)
{//��ż����ķָ�
	LNode *p1 = L, *p2 = L1;
	bool odd = true;
	while(p1->next)
	{
		if(!odd)
		{
			p1 = p1->next;
		}
		else
		{
			p2->next = p1->next;
			p2 = p2->next;
			p1->next = p1->next->next;
		}
		odd = !odd;
	}
	p2->next = L->next;
	p1->next = NULL;
}

void PrintList(LinkList L)
{//������������е�����
    LinkList p = L->next;
    while (p)
    {
        if (p->next != NULL) cout << p->data << " ";
        else cout << p->data;
        p = p->next;
    }
    cout << endl;
}

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		LinkList L=new LNode;
        CreateList_R(L,n);
        LinkList L1=new LNode;    //����������L1
        L1->next=NULL;
        Decollate(L,L1);      //��ż����ķָ�
        PrintList(L1);
	}
	return 0;
}
