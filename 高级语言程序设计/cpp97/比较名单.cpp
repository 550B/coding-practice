/*2151974 ��� ������*/

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list;
class stu_info {
private:
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	int round;
	friend stu_list;
public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];

	/* ���������private���ݳ�Ա�ͳ�Ա���� */
public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������

	/* �������������public��Ա���� */
	stu_info* p = stu;
	void copy(stu_info* p, int num, char ch[], int append);
	void copy2(stu_info* p, int num, char ch[]);
	void stunumsort();
};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
void stu_list::copy(stu_info* p, int num, char ch[], int append)
{
	p->stu_no = num;
	strcpy(p->stu_name, ch);
	p->round = append;
}

void stu_list::copy2(stu_info* p, int num, char ch[])
{
	stu_info* q = p;
	int sign = 0;
	while (--q != stu - 1)
	{
		if (!strcmp(q->stu_name,ch))
		{
			sign = 1;
			q->round = 1;
			break;
		}
	}
	if(!sign)
	{
		stu_list::p->stu_no = num;
		strcpy(stu_list::p->stu_name, ch);
		stu_list::p->round = 2;
		stu_list::p++;
	}
	stu_list::p->stu_no = -1;
}

void stu_list::stunumsort()
{
	int len = p - stu;
	for (int i = 1; i < len; i++)
	{
		for (int j = len - 1; j >= i; j--)
		{
			if (stu[j].stu_no < stu[j - 1].stu_no)
			{
				int tmpr = stu[j - 1].round;
				stu[j - 1].round = stu[j].round;
				stu[j].round = tmpr;
				char tmpch[MAX_NAME_LEN];
				strcpy(tmpch, stu[j - 1].stu_name);
				strcpy(stu[j - 1].stu_name, stu[j].stu_name);
				strcpy(stu[j].stu_name, tmpch);
				int tmpn = stu[j - 1].stu_no;
				stu[j - 1].stu_no = stu[j].stu_no;
				stu[j].stu_no = tmpn;
			}
		}
	}
}

int stu_list::read(const char* filename, const int append)
{
	ifstream in;
	in.open(filename, ios::in | ios::binary);
	if (in.is_open() == 0)
	{
		cout << "�ļ�[" << filename << "]��ʧ��" << endl;
		return -1;
	}

	stu_info* q = stu_list::p;
	while (!in.eof())
	{
		int tmp;
		in >> tmp;
		if (in.fail())
		{
			break;
		}
		char nametmp[MAX_NAME_LEN];
		in >> nametmp;
		if (append)
		{
			copy2(q, tmp, nametmp);
			continue;
		}
		else
		{
			copy(q, tmp, nametmp, append);
		}
		q++;
	}
	if (append)
		stunumsort();
	else
	{
		q->stu_no = -1;
		stu_list::p = q;
	}
	in.close();
	return 0;
}

int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "===========================================================" << endl;
	cout << "��� ѧ��    ����                             ��һ�� �ڶ���" << endl;
	cout << "===========================================================" << endl;
	int cnt = 1;
	stu_info* p = stu;
	while (p->stu_no != -1)
	{
		cout << setiosflags(ios::left) << setw(5) << cnt++;
		cout << p->stu_no << " ";
		cout << setiosflags(ios::left) << setw(33) << p->stu_name;
		if (p->round == 0)
		{
			cout << "Y      �˿�" << endl;
		}
		else if (p->round == 1)
		{
			cout << "Y      Y" << endl;
		}
		else if (p->round == 2)
		{
			cout << "/      ��ѡ" << endl;
		}
		p++;
	}
	cout << "===========================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}