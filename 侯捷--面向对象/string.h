
#ifndef __MYSTRING__
#define __MYSTRING__

class String{
	public:
		//3个构造函数（传值、拷贝构造、拷贝复制）+1个析构函数+ 1个访问函数
		String(const  char* cstr=0);
		String(const String& str);
		String& operator = (const String& str);
		~String();
		char* get_c_str() const { return my_data ;}

	private:
		//一个指针， 指向堆区的字符串
		char* my_data;
};

//String s1("hello");
#include <cstring>
inline String:: String(const char* cstr ){
	if(cstr){
		my_data = new char[strlen(cstr)+1];
		strcpy(my_data, cstr);
	}else {
		my_data= new char[1];
		*my_data= '\0';
	}
}

//String s2(s1)
inline String:: String(const String& str){
	my_data= new char[strlen(str.my_data)+1];
	strcpy(my_data,str.my_data );
}

//操作符重载——拷贝赋值  String s3= s2
inline String&  String::operator=(const String& str){
	if( this ==& str) return *this;
	delete[] my_data;
	my_data = new char[strlen(str.my_data)+1];
	strcpy(my_data, str.my_data);
	return *this;
}

//析构函数
inline String::~String(){
	delete[] my_data;
}


//全局操作符重载 
#include <iostream>
using namespace std;

ostream& operator<< (ostream& os, const String& str){
	os<< str.get_c_str();
	return os;
}

#endif
