#include<bits/stdc++.h>
using namespace std;

void readPapers(string content)
{
	stringstream ss;
	int num = 0, p = 0;
	ss << content;
	string str;
	while(ss >> str)
	{
		for(int i = 0; i < int(str.size()); i++)
			if(str[i] == ',' || str[i] == '.' || str[i] =='"')
				p++;
		num++;
	}
	cout << num << "," << p << endl;
}

int main() 
{
    std::string content;
    std::getline(std::cin, content, '\n');
    readPapers(content);
    return 0;
}
