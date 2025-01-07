#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
	int* base;
	int front;
	int rear;
}SqQueue;
Status InitQueue(SqQueue& Q)
{//构造一个空队列Q
	Q.base = new int[MAXSIZE];
	Q.front = 0;
	Q.rear = 0;
	return OK;
}
Status EnQueue(SqQueue& Q, int e)
{//在Q的队头插入新元素e
	if(Q.rear == (MAXSIZE + Q.front - 1) % MAXSIZE)
		return ERROR;
	Q.base[Q.front] = e;
	Q.front = (MAXSIZE + Q.front - 1) % MAXSIZE;
	return OK;
}
Status DeQueue(SqQueue& Q)
{//删除Q的队尾元素，用e返回其值
	if(Q.front == Q.rear)
		return ERROR;
	int e = Q.base[Q.rear];
	Q.rear = (MAXSIZE + Q.rear - 1) % MAXSIZE;
	return e;
}

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		SqQueue Q;
		InitQueue(Q);          //初始化循环队列
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
