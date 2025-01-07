#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateCirList(LinkList& L, int m)
{//后插法创建单向循环链表
	L = new LNode;
	L->next = NULL;
	LNode* p = L;
	for(int i = 1; i <= m; i++)
	{
		LNode* t = new LNode;
		t->data = i;
		t->next = NULL;
		p->next = t;
		p = t;
	}
	p->next = L->next;
}
void MonkeyKing(LinkList& L, int n)
{//猴子选大王（约瑟夫问题）     直接输出结果
	LNode *p = L;
	while(p->next != p)
	{
		if(n == 1)
		{
			bool flag = false;
			int i = 1;
			while(p->next != L->next || flag == false)
			{	
				
				flag = true;
				if(i == 1)
					cout << i;
				else
					cout << " " << i;
				i++;
				p = p->next;
			}
			cout << endl;
			return ;
		}
		for(int i = 0; i < n - 1; i++)
			p = p->next;
		LNode *t = p->next;
		p->next = t->next;
		cout << t->data << " ";
		delete t;
	}
	cout << p->data << endl;
}

int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(n==0&&m==0) break;
        LinkList L;
        CreateCirList(L,m);
        MonkeyKing(L,n);
    }
    return 0;
}
