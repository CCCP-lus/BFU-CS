#include<bits/stdc++.h>
using namespace std;

template<typename T, int SIZE>
class Queue
{
private:
	vector<T> q;
public:
	Queue<T, SIZE>();
	void push(T);
	T front();
	void pop();
	bool empty();
	int size();
	void clear();
	~Queue();
};

template<typename T, int SIZE>
Queue<T, SIZE>::Queue()
{
	
}

template<typename T, int SIZE>
void Queue<T, SIZE>::push(T a)
{
	q.push_back(a);
}

template<typename T, int SIZE>
T Queue<T, SIZE>::front()
{
	return q.front();
}

template<typename T, int SIZE>
void Queue<T, SIZE>::pop()
{
	q.erase(q.begin());
}

template<typename T, int SIZE>
bool Queue<T, SIZE>::empty()
{
	return q.empty()? true: false;
}

template<typename T, int SIZE>
int Queue<T, SIZE>::size()
{
	return q.size();
}

template<typename T, int SIZE>
void Queue<T, SIZE>::clear()
{
	q.erase(q.begin(), q.end());
}
template<typename T, int SIZE>
Queue<T, SIZE>::~Queue()
{
	
}

int main()
{
    Queue<int, 5> intQueue;   // 可以存放5个int类型元素的队列 
    int tmp_i;
    for (int i = 0; i < 5; i++) // 输入5个整数并入队 
    { 
        cin>>tmp_i;
        intQueue.push(tmp_i);
    } 
    for (int i = 0; i < 5; i++){ // 依次输出5个整数并出队 
        if(i<4)
            cout << intQueue.front() << ' ';
        else cout << intQueue.front()<< '\n';
        intQueue.pop();
    }
    if (intQueue.empty()) cout << "After 5 pops, intQueue is empty." << endl;

    Queue<string, 3> stringQueue; // 可以存放3个string类型元素的队列 
    string tmp_s;
    for (int i = 0; i < 3; i++) // 输入3个字符串并入队
    { 
        cin>>tmp_s;
        stringQueue.push(tmp_s);
    }
    cout << stringQueue.front() << '\n'; // 输出队列中的第1个字符串 
    cout << "There are " << stringQueue.size() << " elements in stringQueue." << '\n';
    stringQueue.clear(); // 清空队列 
    if (stringQueue.empty()) cout << "After clear, there are no elements in stringQueue.";

    return 0;
}
