#include<bits/stdc++.h>
using namespace std;

template<typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
    int a1, a2;
    std::cin >> a1 >> a2;
    Swap(a1, a2);
    std::cout << a1 << "," << a2 << std::endl;

    double b1, b2;
    std::cin >> b1 >> b2;
    Swap(b1, b2);
    std::cout << b1 << "," << b2 << std::endl;

    char c1, c2;
    std::cin >> c1 >> c2;
    Swap(c1, c2);
    std::cout << c1 << "," << c2 << std::endl;

    return 0;
}
