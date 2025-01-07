#include<bits/stdc++.h>
using namespace std;

class CheckedPtr
{
public:
    CheckedPtr(int * b, int * e) : begin(b), end(e), current(b){
    }
    CheckedPtr & operator ++(); // prefix ++
    CheckedPtr & operator --(); // prefix --
    CheckedPtr   operator ++(int); // postfix ++
    CheckedPtr   operator --(int); // postfix --
    int* Begin();
    int* End();
    int* Current();
private:
    int *begin;        //pointer to beginning of the array
    int *end;        //one past the end of the array
    int *current;    //current position within the array
};

CheckedPtr & CheckedPtr::operator ++()
{
	current++;
	return *this;
}

CheckedPtr & CheckedPtr::operator --()
{
	current--;
	return *this;
}

CheckedPtr   CheckedPtr::operator ++(int)
{
	CheckedPtr temp = *this;
	current++;
	return temp;
}
    
CheckedPtr   CheckedPtr::operator --(int)
{
	CheckedPtr temp = *this;
	current--;
	return temp;
}

int* CheckedPtr::Begin()
{
	return begin;
}


int* CheckedPtr::End()
{
	return end;
}


int* CheckedPtr::Current()
{
	return current;
}

int main()
{
    int n;
    std::cin >> n;
    int* array = new int[n];

    for(int i = 0; i < n; i++)
        std::cin >> array[i];

    CheckedPtr cp(array, array+n);
    for(;cp.Current()<cp.End(); cp++)
        std::cout << *cp.Current() << " ";
    std::cout << std::endl;

    for(--cp; cp.Current()>cp.Begin(); cp--)
        std::cout << *cp.Current() << " ";
    std::cout << *cp.Current() << std::endl;

    delete[] array;
    return 0;
}
