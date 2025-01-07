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
void Difference(LinkList& LA, LinkList& LB)
{//求基于链表的两个集合的差集
	LNode *p1 = LA->next, *p2 = LB->next;
	LNode *p3 = LA;
	while(p1 && p2)
	{
		if(p1->data < p2->data)
		{
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}
		else if(p1->data > p2->data)
		{
			p2 = p2->next;
		}
		else
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		if(!p2)
			p3->next = p1;
	}
}

void PrintList(LinkList &L)
{//依次输出链表中的数据和该集合的元素个数
    L=L->next;
    int s=0;
    while(L)
    {
        if(L->next!=NULL) cout<<L->data<<" ";
        else cout<<L->data;
        L=L->next;
        s++;
    }
    cout<<endl<<s<<endl;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        LinkList LA,LB;
        CreateList_R(LA,n);
        CreateList_R(LB,m);
        Difference(LA,LB);
        PrintList(LA);
    }
    return 0;
}
