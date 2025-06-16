#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str[5];
	cout<<"输入5个字符串：\n";
	for(int i=0;i<5;i++)
		cin>>str[i];

	cout<<"排序前，这5个字符串为：\n";
	for(int i=0;i<5;i++)
		cout<<str[i]<<"\n";
	for(int i=0;i<4;i++)
		for(int j=i+1;j<5;j++)
			if(str[i]>str[j])
			{
				string temp;
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
	cout<<"排序后，这5个字符串为：\n";
	for(int i=0;i<5;i++)
		cout<<str[i]<<"\n";

	return 0;
}

+++++++++++++++++++++++++++++++

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	vector<string> v_string;
	string temp;
	for(int i=0;i<5;i++){
		cin>>temp;
		v_string.push_back(temp);
	}
	
	//sort(v_string.begin(),v_string.end(),greater<string>());
	sort(v_string.begin(),v_string.end());
	
	for(int i=0;i<5;i++)
		cout<<v_string[i]<<" ";
	cout<<endl;
	
	return 0;
}