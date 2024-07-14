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
void Search_k(LinkList L, int k)
{
    // 直接输出结果
	LNode* p = L->next;
	for(int i = 0; i < k; i++)
		p = p->next;
	LNode*t = L->next;
	while(p)
	{
		p = p->next;
		t = t->next;
	}
	cout << t->data << endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList L;
        CreateList_R(L,n);
        int k;
        cin>>k;
        Search_k(L,k);
    }
    return 0;
}
