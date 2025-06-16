#include<bits/stdc++.h>
using namespace std;

template<typename T>
void Input(T a[], const int n)
{
	for(int i = 0; i < n; i++)
		cin >> a[i];
}

template<typename T>
void Sort(T a[], const int n)
{
	for(int i = 0; i < n; i++)
	{
		int max = i;
		for(int j = i + 1; j < n; j++)
		{
			if(a[max] < a[j])
			{
				max = j;
			}
		}
		if(max != i)
		{
			T temp;
			temp = a[max];
			a[max] = a[i];
			a[i] = temp;
		}
	}
}

template<typename T>
void Output(T a[], const int n)
{
	for(int i = n - 1; i >= 0; i--)
		if(i > 0) cout << a[i] << ", ";
		else cout << a[i] << endl;
}

int main()
{
    const int LEN = 5;
    int type;
    while (std::cin >> type)
    {
        switch (type) 
        {
            case 0: 
            {
                int a1[LEN];
                Input<int>(a1, LEN); Sort<int>(a1, LEN); Output<int>(a1, LEN);
                break;
            }
            case 1: 
            {
                char a2[LEN];
                Input(a2, LEN); Sort(a2, LEN); Output(a2, LEN); 
                break; 
            }
            case 2: 
            {
                double a3[LEN];
                Input(a3, LEN); Sort(a3, LEN); Output(a3, LEN);
                break;
            }
        }
    }

    return 0;
}
