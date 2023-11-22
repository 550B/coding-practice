/*2151974 ��� ������*/
#include <iostream>
#include <string>
using namespace std;

const int STU = 10;

/***************************************************************************
  �������ƣ�data_in
  ��    �ܣ���������
  ���������string num[STU], string name[STU], int score[STU]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void data_in(string num[STU], string name[STU], int score[STU])
{
	int cnt = 0;
	while (cnt < STU)
	{
		cout << "�������" << cnt + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> num[cnt] >> name[cnt] >> score[cnt];
		cnt++;
	}
}

/***************************************************************************
  �������ƣ�data_sort
  ��    �ܣ���������
  ���������string num[STU], string name[STU], int score[STU]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void data_sort(string num[STU], string name[STU], int score[STU])
{
	for (int i = 0; i < STU; i++)
	{
		for (int j = i + 1; j < STU; j++)
		{
			if (score[i]>score[j])
			{
				string t1;
				t1 = num[j];
				num[j] = num[i];
				num[i] = t1;
				string t2;
				t2 = name[j];
				name[j] = name[i];
				name[i] = t2;
				int t = score[j];
				score[j] = score[i];
				score[i] = t;
			}
		}
	}
}

/***************************************************************************
  �������ƣ�data_out
  ��    �ܣ����
  ���������string num[STU], string name[STU], int score[STU]
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void data_out(string num[STU], string name[STU], int score[STU])
{
	cout << endl << "����������(�ɼ�����):" << endl;
	for (int i = 0; i < STU; i++)
	{
		if (score[i] < 60)
		{
			cout << name[i] << " " << num[i] << " " << score[i] << endl;
		}
	}
}

/***************************************************************************
  �������ƣ�main
  ��    �ܣ����ú���
  ���������
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int main()
{
	string num[STU], name[STU];
	int score[STU];
	data_in(num, name, score);
	data_sort(num, name, score);
	data_out(num, name, score);

	return 0;
}