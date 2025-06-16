#include<iostream>
#include<cstring>
using namespace std;

class String{
	private:
		char *str;
	public:
		String(); // String s;
		String(const char *); // String s("hello");
		String(const String &); // String s(s2);
		~String();
		String & operator=(const String &); // s1 = s2;
		String & operator=(const char *); // s1 = "world";
		friend String operator+(const String &, const String &);
		// cout<<s1<<s2;
		friend ostream & operator<<(ostream &, const String &);
};

String::String(){
	str = NULL;
}

String::String(const char *s){
	str = new char[strlen(s)+1];
	strcpy(str,s);
}

String::String(const String & s){  // String s; String s2(s);
	if(s.str!=NULL){
		str = new char[strlen(s.str)+1];
		strcpy(str,s.str);
	}else str = NULL;
}

String::~String(){
	if(str!=NULL){
		delete [] str;
		str = NULL;
	}
}

String & String::operator=(const String & s){
	if(s.str!=NULL){
		if(str!=NULL){
			delete [] str;
		}
		str = new char[strlen(s.str)+1];
		strcpy(str,s.str);		
	}else{
		if(str!=NULL){
			delete [] str;
			str = NULL;
		}
	}	
}

String & String::operator=(const char *s){
	if(str!=NULL){
		delete [] str;
	}
	str = new char[strlen(s)+1];
	strcpy(str,s);	
}

String operator+(const String & s1, const String & s2){  // s1+s2
	if(s1.str==NULL){
		String tmp(s2);
		return tmp;
	}else if(s2.str==NULL){
		String tmp(s1);
		return tmp;
	}else{
		String tmp;
		tmp.str = new char[strlen(s1.str)+strlen(s2.str)+1];
		strcpy(tmp.str,s1.str);
		strcat(tmp.str,s2.str);
		return tmp;
	}
}

ostream & operator<<(ostream & os, const String & s){
	if(s.str!=NULL)
		os<<s.str;
	return os;
}

int main(){
	String s1("hello ");
	String s2(s1);
	cout<<s1+s2<<endl;
	//String s3("world");
	//s2 = s3;
	s2 = "world";
	cout<<s1+s2<<endl;
	
	return 0;
}

