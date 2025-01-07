#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 0
#define OVERFLOW -1
#define ERROR -2
typedef int Status;
typedef struct
{
	int* base;
	int front, rear, tag;
}SqQueue;
Status InitQueue(SqQueue& Q)
{//构造一个空队列Q
	Q.base = new int[MAXSIZE];
	Q.tag = 0;
	Q.front = 0;
	Q.rear = 0;
	return OK;
}
Status EnQueue(SqQueue& Q, int e)
{//插入元素e为Q的新的队尾元素
	if(Q.tag == 1 && Q.front == Q.rear)
		return ERROR;
	else
	{
		Q.base[Q.rear] = e;
		Q.rear = (Q.rear + 1) % MAXSIZE;
		if(Q.front == Q.rear)
			Q.tag = 1;
	}
	return OK;
}
Status DeQueue(SqQueue& Q)
{//删除Q的队头元素，用e返回其值
	int e;
	if(Q.tag == 0 && Q.front == Q.rear)
		return ERROR;
	else
	{
		e = Q.base[Q.front];
		Q.front = (Q.front + 1) % MAXSIZE;
	}
	return e;
}

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		SqQueue Q;
		InitQueue(Q);             //初始化循环队列
		for(int i=0;i<n;i++)
		{//n个元素入队
			int x;cin>>x;
			EnQueue(Q,x);
		}
		for(int i=0;i<n-1;i++)
			cout<<DeQueue(Q)<<" ";
		cout<<DeQueue(Q)<<endl;
	}
	return 0;
}
