#include"String_class.h"
#pragma warning(disable:4996)

/*���캯������һ���ַ����������String�ĳ�ʼ����Ĭ�ϵ��ַ�������Ϊ�ա�
����ĺ��������в���Ҫ�ٶ��������Ĭ��ֵ����Ϊ�������Ѿ��������ˡ�
���⣬����C����strlen��ʱ����Ҫע���ַ��������Ƿ�Ϊ�գ��Կ�ָ�����strlen�������ڴ����*/
MyString::MyString(const char *str)
{
	if (str == NULL) 
	{
		length = 0;
		data = new char[1];
		*data = '\0';
	}
	else
	{
		length = strlen(str);
		data = new char[length + 1];
		strcpy(data, str);
	}
}

//�������캯����Ҫ�������
MyString::MyString(const MyString &str)
{
	length = str.size();
	data = new char[length + 1];
	strcpy(data, str.c_str());

}

//����������Ҫ�����ڴ���ͷż����ȵĹ���
MyString::~MyString()
{
	delete []data;
	length = 0;
}

//�����ַ�����ֵ���㣬��������ı�ԭ���ַ�����ֵ��Ϊ�˱����ڴ�й¶��
//�����ͷ���ԭ��������ڴ�����������һ���ʵ���С���ڴ����µ��ַ���
MyString &MyString::operator=(const MyString &str)//����
{
	if (this == &str)
	{
		return *this;
	}

	delete []data;
	length = str.length;
	data = new char[length + 1];
	strcpy(data, str.c_str());
	return *this;
}

int MyString::size() const
{
	return length;
}

const char* MyString::c_str() const
{
	return data;
}