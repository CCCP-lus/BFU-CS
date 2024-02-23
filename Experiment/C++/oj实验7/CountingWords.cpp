#include<bits/stdc++.h>
using namespace std;

unsigned int termFrequency(string& content, map<string, unsigned int>& msu)
{
	for(int i = 0; i < int(content.size()); i++)
		if(content[i] == ',' || content[i] == '.' || content[i] =='"')
			content[i] = ' ';
	stringstream ss; ss << content;
	for(string str; ss >> str;)
	{
		bool flag = false;
		for(int i = 0; i < int(str.size()); i++)
		{
			if(!(str[i] >= '0' && str[i] <= '9'))
			{
				flag = true;
				break;
			}
		}
		if(flag == true)
		{
			transform(str.begin(), str.end(), str.begin(), ::tolower);
			map<string, unsigned int>::iterator it = msu.find(str);
			if(msu.count(str) == 0) 
				msu.insert(map<string, unsigned int>::value_type(str, 1));
			else 
				it ->second++;
		}
	}
	return msu.size();
}

void alphabetSortedFrequency(map<string, unsigned int>& msu)
{
	for(map<string, unsigned int>::iterator it = msu.begin(); it != msu.end(); it++)
	{
		cout << it ->first << ":" << it ->second << endl;
	}
}

int main() 
{
    // 从标准输入获取文本串
    std::string content;
    std::getline(std::cin, content, '\n');

    map<std::string, unsigned int> msu;

    // 要求termFrequency实现分词，去掉标点
    // 获取单词存放在map中，记录词频（出现次数）
    // 最后返回不重复的单词数量    
    unsigned int nWords = termFrequency(content, msu);

    // 按首字母A-Z排序一行一词输出词频
    alphabetSortedFrequency(msu);

    return 0;
}
