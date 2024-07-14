#include<bits/stdc++.h>
using namespace std;

template<class T, int SIZE = 20>
class Stack
{
private: 
    T    array[SIZE];        //数组，用于存放栈的元素
    int top;                //栈顶位置（数组下标）
public:
    Stack();                //构造函数，初始化栈
    void Push(const T & );  //元素入栈
    T Pop();                //栈顶元素出栈
    void Clear();           //将栈清空
    const T & Top() const;  //访问栈顶元素
    bool Empty() const;     //测试栈是否为空
    bool Full() const;     //测试是否栈满
    int Size();            //返回当前栈中元素个数
};

template<class T, int SIZE>
Stack<T, SIZE>::Stack()
{
	top = -1;
}

template<class T, int SIZE>
void Stack<T, SIZE>::Push(const T& a)
{
	if(Full() == false)
	{
		array[++top] = a;
	}
}

template<class T, int SIZE>
T Stack<T, SIZE>::Pop()
{
	if(Empty() == false)
	{
		top--;
		return array[top];
	}
	else exit(1);
}

template<class T, int SIZE>
void Stack<T, SIZE>::Clear()
{
	top = -1;
}

template<class T, int SIZE>
const T & Stack<T, SIZE>::Top() const
{
	if(Empty() == false) return array[top];
	else exit(1);
}

template<class T, int SIZE>
bool Stack<T, SIZE>::Empty() const
{
	return (top == -1)? true: false;
}

template<class T, int SIZE>
bool Stack<T, SIZE>::Full() const
{
	return (top == SIZE - 1)? true: false;
}

template<class T, int SIZE>
int Stack<T, SIZE>::Size()
{
	return top + 1;
}

int main()
{
    Stack<int, 10> intStack;

    int n;
    cin >> n; //n<=10
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        intStack.Push(temp);
    }

    for (int i = 0; i < n; i++)
    {
        cout << intStack.Top() << " ";
        intStack.Pop();
    }
    cout<<endl;

    if(intStack.Empty())
        cout<<"Now, intStack is empty."<<endl;

    Stack<string,5> stringStack;
    stringStack.Push("One");
    stringStack.Push("Two");
    stringStack.Push("Three");
    stringStack.Push("Four");
    stringStack.Push("Five");
    cout<<"There are "<<stringStack.Size()<<" elements in stringStack."<<endl;
    stringStack.Clear();
    if(stringStack.Empty()) 
        cout<<"Now, there are no elements in stringStack"<<endl;

    return 0;
}
