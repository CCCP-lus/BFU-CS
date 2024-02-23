#include<bits/stdc++.h>
using namespace std;

template<class T>
class VectorN
{
private:
    int dim;
    T* values;
public:
    VectorN<T>();
    VectorN<T>(int, T*);
    VectorN<T>(const VectorN<T>& x);
    VectorN<T>& operator =(const VectorN& t);
    T Mag() const;
    ~VectorN<T>();
};

template<class T>
VectorN<T>::VectorN()
{
    dim = 0;
    values = 0;
}

template<class T>
VectorN<T>::VectorN(int a, T* b)
{
    dim = a;
    values = new T[a];
    for(int i = 0; i < a; i++)
    	values[i] = b[i];
}

template <class T>
VectorN<T>::VectorN(const VectorN<T>& x)
{
	dim = x.dim;
	values = new T[dim];
	for(int i = 0; i < dim; i++)
	    values[i] = x.values[i];
}

template <class T>
VectorN<T> & VectorN<T>::operator=(const VectorN& t)
{
	if(values) 
		delete[] values;
	dim = t.dim;
	values = new T[dim];
	for(int i = 0 ; i < t.dim; i++)
	{
		values[i] = t.values[i];
	}
	return *this;
}

template<class T>
T VectorN<T>::Mag() const//求向量的模，为各分量平方和之后再开根号。
{
	double sum = 0.0;
	for(int i = 0; i < dim; i++)
	{
		sum += values[i] * values[i];
	}
	sum = T(sqrt(sum));
	return sum;
}

template<class T>
VectorN<T>::~VectorN()
{
	if(values) 
		delete[] values;
}

int main()
{

    int num;
    cin >> num;
    int* temp = new int[num];
    for (int i = 0; i < num; i++)
        cin >> temp[i];
    VectorN<int> vn1(num, temp);
    delete[] temp;

    VectorN<int> vn2 = vn1;

    cout << vn2.Mag() << endl;

    cin >> num;
    double* dtemp = new double[num];
    for (int i = 0; i < num; i++)
        cin >> dtemp[i];
    VectorN<double> vn3(num, dtemp);
    delete[] dtemp;

    VectorN<double> vn4;
    vn4 = vn3;
    cout << vn4.Mag() << endl;

    return 0;
}
