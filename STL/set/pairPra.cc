#include<iostream>
#include<string>
using namespace std;

int main()
{
	//��һ�ַ�ʽ������һ��pair
	pair<int, string> mypair(10, "aaa");
	cout << mypair.first << "  " << mypair.second << endl;

	//�ڶ��� ����pair
	pair<string, string> mypair2 = make_pair("aaa", "bbb");
	//auto mypair2 = make_pair("aaa", "bbb");
	cout << mypair2.first << "  " << mypair2.second << endl;

	//������
	pair<int, string> mypair3 = mypair;//��������
	cout << mypair3.first << "  " << mypair3.second << endl;

	getchar();
	return 0;
}