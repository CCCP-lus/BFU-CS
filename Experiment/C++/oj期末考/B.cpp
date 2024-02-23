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

    intArray test(array,N);   // ���ù��캯�� 
    intArray copytest(test);  // ���ÿ������캯��
    copytest = test;     // �������صĸ�ֵ����� = 
    cout<<copytest.sum();  // ����sum������������ĺͣ�֮������� 

    delete [] array;

    return 0;
}
