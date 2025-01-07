#include<bits/stdc++.h>

bool cmp(char a, char b)
{
	return a < b;
}

int main()
{
	std::string s;
	std::cin >> s;
	std::sort(s.begin(), s.end(), cmp);
	std::cout << s;
	return 0;
}
