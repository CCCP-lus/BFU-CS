#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> vec(10);
	typedef ostream_iterator<string> output;
	cout << "输入若干个字符串，以-1结束:";
	int i;
	for (i = 0; i< (int)vec.size(); i++)
	{
		cin >> vec[i];
		if (vec[i] == "-1")
			break;
	}
	cout << "输入的" << i << "个字符串分别为：";
	copy(vec.begin(), vec.begin() + i, output(cout, " "));
	cout << "\n";
	string str;
	cout << "输入要查找的字符串";
	cin >> str;
	vector<string>::iterator it;
	it = find(vec.begin(), vec.begin() + i, str);
	if (it != vec.end())
		cout << *it << "字符串存在" <<endl;
	else
		cout << "该字符串不存在" << endl;

	return 0;
}