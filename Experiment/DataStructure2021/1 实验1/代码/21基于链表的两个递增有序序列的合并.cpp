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
void MergeList(LinkList& LA, LinkList& LB)
{//求基于链表的两个递增有序序列的合并    存入LA
	LNode *p1 = LA, *p2 = LB;
	p1 = p1->next; p2 = p2->next;
	LinkList LC = LA;
	LNode* p3 = LC;
	while(p1 && p2)
	{
		if(p1->data < p2->data)
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else if(p1->data > p2->data)
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;			
		}
		else
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
			p2 = p2->next;			
		}
	}
	p3->next = p1?p1:p2;
	delete LB;
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
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        LinkList LA,LB;
        CreateList_R(LA,n);
        CreateList_R(LB,m);
        MergeList(LA,LB);
        PrintList(LA);
    }
    return 0;
}
