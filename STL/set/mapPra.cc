#include<iostream>
#include<map>
#include<string>
using namespace std;

//map������ʼ��
void test0()
{
	//map������ģ����� ����Ҫָ��key���ͣ�value������
	map<int, string> mymap1;//Ĭ�Ϲ���
	map<int, string> mymap2(mymap1); //��������
}

//map�������
void test1()
{
	map<int, int> mymap0;

	//��һ�ֲ��뷽ʽ
	mymap0.insert(pair<int, int>(1, 5));
	//�ڶ��ֲ��뷽ʽ
	mymap0.insert(make_pair(2, 10));
	//�����ֲ��뷽ʽ
	mymap0.insert(map<int, int>::value_type(3, 15));
	//�����ֲ��뷽ʽ
	mymap0[4] = 20;//���key���ڣ����޸�����ָ��keyԪ�ص�ֵ

	//���в��뷽ʽ������
	mymap0[2] = 100;//���ַ�ʽ�����޸�

	//�������ʵ�key�����ڣ���������������ݲ����ȥ
	cout << " key :" << mymap0[20] << endl;

	pair<map<int, int>::iterator, bool> ret = mymap0.insert(map<int, int>::value_type(3, 15));
	if (ret.second)
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}

	pair<map<int, int>::iterator, bool> ret1 = mymap0.insert(map<int, int>::value_type(5, 15));
	if (ret1.second)
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}

	for (map<int, int>::iterator it = mymap0.begin(); it != mymap0.end(); ++it)
	{
		cout << "key = " << it->first << "  " << "value = " << it->second << endl;
	}


}

int main()
{
	cout << "-----------test1-----------" << endl;
	test1();
	return 0;
}