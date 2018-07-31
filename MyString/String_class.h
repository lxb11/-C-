#ifndef _STRING_CLASS_
#define _STRING_CLASS_
#include<iostream>
using namespace std;

class MyString
{
public:
	MyString(const char *str = NULL);//ͨ�ù��캯��
	MyString(const MyString &str);//�������캯��
	~MyString();//��������
	MyString& operator=(const MyString &str);//����=

	int size() const; //��ȡ����
	const char *c_str() const;//��ȡC�ַ�������

private:
	char *data;
	int length;
};

#endif // !String_class



