#include<bits/stdc++.h>
using namespace std;

class intArray
{
private:
	int *arr;
	int len;
public:
	intArray(int*, int);
	intArray(const intArray&);
	intArray & operator=(const intArray&);
	int sum();
	~intArray();
};

intArray::intArray(int* a, int n)
{
	len = n;
	arr = new int[n];
	for(int i = 0; i < len; i++)
		arr[i] = a[i];
} 

intArray::intArray(const intArray& a)
{
	arr = new int[a.len];
	for(int i = 0; i < len; i++)
		arr[i] = a.arr[i];	
	len = a.len;
}

intArray & intArray::operator=(const intArray& a)
{
	arr = new int[a.len];
	for(int i = 0; i < len; i++)
		arr[i] = a.arr[i];		
	len = a.len;
	return *this;
}

int intArray::sum()
{
	int sum = 0;
	for(int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

intArray::~intArray()
{
	delete[] arr;
}

int main()
{
    int N;
    cin>>N;
    int * array = new int[N];
    for(int i=0;i<N;i++)
        cin>>array[i];

    intArray test(array,N);   // 调用构造函数 
    intArray copytest(test);  // 调用拷贝构造函数
    copytest = test;     // 调用重载的赋值运算符 = 
    cout<<copytest.sum();  // 调用sum函数计算数组的和，之后输出和 

    delete [] array;

    return 0;
}
