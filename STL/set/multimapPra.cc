#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

#define SALE_DEPARTMENT 1 //���۲���
#define DEV_DEPARTMENT 2 //������
#define FINACIAL_DEPARTMENT 3 //����

//multimap ����
//��˾������Ƹ��5��Ա����5��Ա�����빫˾֮����Ҫָ��Ա�����ĸ����Ź���
//��Ա��Ϣ�ɣ����� ���� �绰 ���ʵ����
//ͨ��multimap������Ϣ�� ���� ���� ��ʾ
//�ֲ�����ʾԱ����Ϣ����ʾȫ��Ա����Ϣ


class Yuangong
{
public:
	string name;
	int age;
	double salary;
	string tele;
};

//����Ա�� 5��
void CreateYuangong(vector<Yuangong>& v)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; ++i)
	{
		Yuangong yg;
		yg.name = "Ա��";
		yg.name += nameseed[i];

		yg.age = rand() % 30;
		yg.salary = rand() % 10000 + 10000;
		yg.tele = "+86-88888888";

		v.push_back(yg);
	}
}

//��Ա��ָ�ɲ���
void  SetYGgroup(vector<Yuangong>& v, multimap<int, Yuangong>& group)
{
	for (vector<Yuangong>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "��ǰԱ����Ϣ��" << endl;
		cout << "���֣�" << it->name << endl;
		cout << "���䣺 " << it->age << endl;
		cout << "����:" << it->salary << endl;
		cout << "�绰��" << it->tele << endl;

		int departmentID = -1;
		while (true)
		{
			cout << "�����벿��(1.���۲� 2.������ 3.����)" << endl;
			cin >> departmentID;

			if (departmentID == SALE_DEPARTMENT)
			{
				group.insert(make_pair(SALE_DEPARTMENT, *it));
				break;
			}
			else if (departmentID == DEV_DEPARTMENT)
			{
				group.insert(make_pair(DEV_DEPARTMENT, *it));
				break;
			}
			else if (departmentID == FINACIAL_DEPARTMENT)
			{
				group.insert(make_pair(FINACIAL_DEPARTMENT, *it));
				break;
			}
			else
			{
				cout << "������� ���������룺" << endl;
			}
		}
	}
}

//��ӡԱ����Ϣ
void ShowYGInfo(multimap<int, Yuangong>& group)
{
	cout << "----------------showYGInfo()----------" << endl;
	int depaertmentID = -1;
	while (true)
	{
		cout << "�����벿��(1.���۲� 2.������ 3.����)�� 0.����" << endl;
		cin >> depaertmentID;

		if (depaertmentID < 1 || depaertmentID > 3)
		{
			continue;
		}
		if (!depaertmentID)
		{
			break;
		}
		multimap<int, Yuangong>::iterator pos = group.find(depaertmentID);
		int num = group.count(depaertmentID);
		while (pos != group.end() && num)
		{
			cout << "��ǰԱ����Ϣ��" << endl;
			cout << "���֣�" << pos->second.name << endl;
			cout << "���䣺 " << pos->second.age << endl;
			cout << "����:" << pos->second.salary << endl;
			cout << "�绰��" << pos->second.tele << endl;
			++pos;
			--num;
		}
	}
}

int main()
{
	vector<Yuangong> v;//��Ա����Ϣ��δ����֮ǰ
	multimap<int, Yuangong> Ygroup;//��ŷ�����Ա����Ϣ
	CreateYuangong(v);//����Ա�� 5��
	SetYGgroup(v, Ygroup);
	ShowYGInfo(Ygroup);

	return 0;
}