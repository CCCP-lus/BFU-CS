#include<iostream>
using namespace std;
typedef int Status;
typedef struct QNode
{//队列的链式存储结构
    int data;
    struct QNode* next;
}QNode, * QueuePtr;
typedef struct
{
    QueuePtr rear;    //只设一个队尾指针
}LinkQueue;
Status EmptyQueue(LinkQueue Q)
{//判断队列是否为空，空返回1，否则返回0
//队列只有一个头结点，即当头结点的指针域指向自己时，队列为空
	if(Q.rear->next->next == Q.rear->next)
		return 1;
	return 0;
}
void EnQueue(LinkQueue& Q, int e)
{//入队，插入元素e为Q的新的队尾元素
	QNode* p = new QNode;
	p->data = e;
	p->next = Q.rear->next;
	Q.rear->next = p;
	Q.rear = p;
}
void DeQueue(LinkQueue& Q)
{//出队，输出Q的队头元素值，后将其删除
	QNode* t = Q.rear->next->next;
	cout << t->data << " ";
	Q.rear->next->next = t->next;
	if(Q.rear == t)
		Q.rear = Q.rear->next->next;
	delete t;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		LinkQueue Q;           //初始化一个带头结点的循环链表
		Q.rear=new QNode;
        Q.rear->next=Q.rear;
		while(n--)
		{//n个元素入队
			int e;cin>>e;
			EnQueue(Q,e);
		}
		while(m--)            //m个元素出队
			DeQueue(Q);
		if(EmptyQueue(Q))
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;
	}
	return 0;
}
