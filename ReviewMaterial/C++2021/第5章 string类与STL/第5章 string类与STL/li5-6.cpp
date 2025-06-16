#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

//copy函数的参数都是迭代器
// #include <algorithm>    
//output_iterator copy( input_iterator start, input_iterator end, output_iterator dest );
//The copy function copies the elements between start and end to dest. 
//In other words, after copy has run,   
//*dest = *start   *(dest+1) = *(start+1)   *(dest+2) = *(start+2)   ...   *(dest+N) = *(start+N)

int main()
{
	typedef vector<int> int_vector;
	typedef istream_iterator<int> input;
	typedef ostream_iterator<int> output;

	//插入适配器，它的作用是引导copy算法每次在容器末端插入一个数据
	typedef back_insert_iterator<int_vector> ins; 

	int_vector vec;

	cout<<"输入若干个整数，以非数字结束：";

	//三个参数分别为起始位置、结束位置和目的地

	//前两个参数是两个迭代器的临时对象，前一个指向整型输入数据流的开始，后一个则指向"pass-the-end value"。

	//第一个迭代器从开始位置每次累进，最后到达第二个迭代器所指向的位置

	copy(input(cin),input(),ins(vec));

	cout<<"输入的"<<vec.size()<<"个整数分别为：";

	//output(cout, " ")展开后的形式是：ostream_iterator(cout, " ")，其效果是产生一个处理输出数据流的迭待器对象，//其位置指向数据流的起始处，并且以" "作为分割符。copy函数将会从头至尾将vector中的内容"拷贝"到输出设备，
//第一个参数所代表的迭代器将会从开始位置每次累进，最后到达第二个参数所代表的迭代器所指向的位置。

	copy(vec.begin(),vec.end(),output(cout," ")); 

	cout<<endl;
	return 0;
}