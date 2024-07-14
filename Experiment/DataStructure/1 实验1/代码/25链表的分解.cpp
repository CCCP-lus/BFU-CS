#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//后插法创建单链表
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
void Decompose(LinkList& LA, LinkList& LB, LinkList& LC)
{//链表的分解    LA->LB、LC
	LB = new LNode;
	LB -> next = NULL;
	LC = new LNode;
	LC -> next = NULL;
	LNode *p1 = LA->next;
	LNode *p2 = LB, *p3 = LC;
	while(p1)
	{
		if(p1->data < 0)
		{
			p2->next = p1;
			p2 = p2->next;
		}
		else
		{
			p3->next = p1;
			p3 = p3->next;
		}
		p1 = p1->next;
	}
	p2->next = NULL;
	p3->next = NULL;
}

void PrintList(LinkList &L)
{//打印依次输出链表中的数据
    L=L->next;
    while(L){
        if(L->next!=NULL) cout<<L->data<<" ";
        else cout<<L->data;
        L=L->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList LA,LB,LC;
        CreateList_R(LA,n);
        Decompose(LA,LB,LC);
        PrintList(LB);
        PrintList(LC);
    }
    return 0;
}
