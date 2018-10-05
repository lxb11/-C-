#include<iostream>
#include<set>
#include<functional>
using namespace std;

void printSet(set<int>& myset)
{
	for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//��ʼ��
void test0()
{
	set<int> myset1;//Ĭ�Ϲ���
	set<int> myset2; //��������
}

//set���������ɾ��
void test1()
{
	set<int> myset1;
	myset1.insert(4);
	myset1.insert(5);
	myset1.insert(3);
	myset1.insert(2);
	myset1.insert(1);
	::printSet(myset1);

	//ɾ��
	myset1.erase(myset1.begin());//ɾ����һ��Ԫ��
	::printSet(myset1);
	myset1.erase(2);//����Ԫ��ֵɾ��
	::printSet(myset1);
	myset1.erase(myset1.begin(), myset1.end());//myset1.clear();
	::printSet(myset1);
}

//����
class mycompaer2 
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test2()
{
	//��������Ҳ�зº���
	mycompaer2 mycom;
	cout << mycom(10, 20) << endl;

	//set<int> myset;//Ĭ�ϴ�С��������
	set<int, greater<int>> myset;
	myset.insert(4);
	myset.insert(2);
	myset.insert(1);
	myset.insert(5);
	for (set<int, greater<int>>::iterator it = myset.begin(); it != myset.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
	set<int>::iterator pos = myset.find(20);//����ֵΪ2��Ԫ�����ڵ�λ��
	if (pos == myset.end())
	{
		cout << "û�в��ҵ�! " << endl;
	}
	else
	{
		cout << "���ҵ� ��" << *pos << endl;
	}
}

class Teacher 
{
public:
	int _id;
	int _age;
	Teacher(int id, int age): _id(id), _age(age){}
};

class mycompare3
{
public:
	bool operator()(Teacher t1, Teacher t2)
	{
		return t1._id > t2._id;
	}
};
void test3()
{
	set<Teacher,mycompare3> myset;
	Teacher t1(1, 2), t2(3, 4), t3(5, 6);
	myset.insert(t1);
	myset.insert(t2);
	myset.insert(t3);
	for (set<Teacher>::iterator it = myset.begin(); it != myset.end(); ++it)
	{
		cout << it->_id << "  " << it->_age << endl;
	}

	//set<Teacher>::iterator pos = myset.find(t2);
	//if (pos == myset.end())
	//{
	//	cout << "û�в��ҵ�! " << endl;
	//}
	//else
	//{
	//	cout << "���ҵ� ��" << pos->_id << "  " << pos->_age << endl;
	//}

	set<Teacher>::iterator pos = myset.find(Teacher(3, 10));//���� _id����
	if (pos == myset.end())
	{
		cout << "û�в��ҵ�! " << endl;
	}
	else
	{
		cout << "���ҵ� ��" << pos->_id << "  " << pos->_age << endl;
	}
}

void test4()
{
	set<int> myset;
	myset.insert(10);
	myset.insert(5);
	myset.insert(1);
	myset.insert(8);
	myset.insert(9);

	set<int>::iterator pos = myset.lower_bound(5); //���ش��ڵ���5 ������
	if (pos == myset.end())
	{
		cout << "û���ҵ���" << endl;
	}
	else
	{
		cout << "���ҵ� ��" << *pos << endl;
	}

	pair<set<int>::iterator, set<int>::iterator> pos2 = myset.equal_range(5);
	if (pos2.first == myset.end())
	{
		cout << "û���ҵ���" << endl;
	}
	else
	{
		cout << "�ҵ���" << *(pos2.first) << endl;
	}

	if (pos2.second == myset.end())
	{
		cout << "û���ҵ���" << endl;
	}
	else
	{
		cout << "�ҵ���" << *(pos2.second) << endl;
	}
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}