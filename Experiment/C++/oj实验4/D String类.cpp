#include<bits/stdc++.h>
using namespace std;

class String{
private:
    char * s;
public:
    String();
    String(const char *);
    String(const String &);
    ~String();
    String & operator=(const char *);
    String & operator=(const String &);
    String operator+(const char *);
    String operator+(const String &);
    String & operator+=(const char *);
    String & operator+=(const String &);
    friend istream & operator>>(istream &, String &);
    friend ostream & operator<<(ostream &, const String &);
    friend bool operator==(const String &, const char *);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const char *);
    friend bool operator!=(const String &, const String &);
};

String::String()
{
	s = new char[421];
	strcpy(s, "");
}

String::String(const char * c)
{
	s = new char[1 + strlen(c)];
	strcpy(s, c);
}

String::String(const String & c)
{
	s = new char[1 + strlen(c.s)];
	strcpy(s, c.s);
}

String::~String()
{
	delete [] s;
}

String & String::operator=(const char * c)
{
	s = new char[1 + strlen(c)];
	strcpy(s, c);
	return *this;
}

String & String::operator=(const String & c)
{
	s = new char[1 + strlen(c.s)];
	strcpy(s, c.s);
	return *this;
}

String String::operator+(const char * c)
{
	strcat(s, c);
	return *this;
}

String String::operator+(const String & c)
{
	strcat(s, c.s);
	return *this;
}

String & String::operator+=(const char * c)
{
	String temp;
	temp.s = new char[1 + strlen(c) + strlen(s)];
	strcpy(temp.s, s);
	strcat(temp.s, c);
	strcpy(s, temp.s);
	return *this;
}

String & String::operator+=(const String & c)
{
	String temp;
	temp.s = new char[1 + strlen(c.s) + strlen(s)];
	strcpy(temp.s, s);
	strcat(temp.s, c.s);
	strcpy(s, temp.s);
	return *this;
}

istream & operator>>(istream & in, String & c)
{
	cin >> c.s;
	return in;
}

ostream & operator<<(ostream & out, const String & c)
{
	cout << c.s;
	return out;
}

bool operator==(const String & a, const char * b)
{
	return ~strcmp(a.s, b);
}

bool operator==(const String & a, const String & b)
{
	return ~strcmp(a.s, b.s);
}

bool operator!=(const String & a, const char * b)
{
	return strcmp(a.s, b);
}

bool operator!=(const String & a, const String & b)
{
	return strcmp(a.s, b.s);	
}

int main()
{
	String s;
	s += "hello";
	cout<<s<<endl;
	String s1("String1");
	String s2("copy of ");
	s2 += "String1";
	cout << s1 << "\n" << s2 << endl;
	String s3;
	cin >> s3;
	cout << s3 << endl;
	String s4("String4"), s5(s4);
	cout << (s5 == s4) << endl;
	cout << (s5 != s4) << endl;
	String s6("End of "), s7("my string.");
	s6 += s7;
	cout << s6 << endl;
	return 0;
}
