/*2151974 ��� ������*/
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�daxie
  ��    �ܣ������д��0~9
  ���������num,flag_of_zero
  �� �� ֵ����
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* ������� */
	cout << "������[0-100��)֮�������:" << endl;

	double num;
	int shiyi = 0, yi = 0, qianwan = 0, baiwan = 0, shiwan = 0, wan = 0, qian = 0, bai = 0, shi = 0, yuan = 0, jiao = 0, fen = 0;
	int a = 0;
	int zero1 = 0;

	cin >> num;

	shiyi = (int)(num / 1000000000);
	a = (int)(num - shiyi * 1000000000.0);
	yi = (a / 100000000) % 10;
	qianwan = (a / 10000000) % 10;
	baiwan = (a / 1000000) % 10;
	shiwan = (a / 100000) % 10;
	wan = (a / 10000) % 10;
	qian = (a / 1000) % 10;
	bai = (a / 100) % 10;
	shi = (a / 10) % 10;
	yuan = a % 10;
	jiao = (int)((num - shiyi * 1000000000.0 - yi * 100000000.0 - qianwan * 10000000.0 - baiwan * 1000000.0 - shiwan * 100000.0 - wan * 10000.0 - qian * 1000.0 - bai * 100.0 - shi * 10.0 - yuan + 0.000001) * 10);
	fen = ((int)((num - shiyi * 1000000000.0 - yi * 100000000.0 - qianwan * 10000000.0 - baiwan * 1000000.0 - shiwan * 100000.0 - wan * 10000.0 - qian * 1000.0 - bai * 100.0 - shi * 10.0 - yuan - jiao * 0.1 + 0.000001) * 10000) / 100 % 10);

	cout << "��д�����:" << endl;
	//#########################################################
	//ʮ�ڵ���
	daxie(shiyi, zero1);
	if (shiyi != 0)
	{
		cout << "ʰ";
	}
	//#########################################################
	daxie(yi, zero1);
	if (shiyi || yi)
	{
		cout << "��";
	}
	//#########################################################
	//ǧ����
	if ((qianwan == 0) && (shiyi || yi) && baiwan)
	{
		zero1 = 1;
	}
	daxie(qianwan, zero1);
	if (qianwan != 0)
	{
		cout << "Ǫ";
	}
	zero1 = 0;
	//#########################################################
	if ((baiwan == 0) && (shiyi || yi || qianwan) && shiwan)
	{
		zero1 = 1;
	}
	daxie(baiwan, zero1);
	if (baiwan != 0)
	{
		cout << "��";
	}
	zero1 = 0;
	//#########################################################
	if ((shiwan == 0) && (shiyi || yi || qianwan || baiwan) && wan)
	{
		zero1 = 1;
	}
	daxie(shiwan, zero1);
	if (shiwan != 0)
	{
		cout << "ʰ";
	}
	zero1 = 0;
	//#########################################################
	/*if ((wan == 0) && (shiyi || yi || qianwan || baiwan || shiwan))
	{
		zero1 = 1;
	}*/
	daxie(wan, 0);
	if (qianwan || baiwan || shiwan || wan)
	{
		cout << "��";
	}
	//zero1 = 0;
	//#########################################################
	//ǧ��Բ
	if ((qian == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan) && bai)
	{
		zero1 = 1;
	}
	daxie(qian, zero1);
	if (qian != 0)
	{
		cout << "Ǫ";
	}
	zero1 = 0;
	//#########################################################
	if ((bai == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian) && shi)
	{
		zero1 = 1;
	}
	daxie(bai, zero1);
	if (bai != 0)
	{
		cout << "��";
	}
	zero1 = 0;
	//#########################################################
	if ((shi == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai) && yuan)
	{
		zero1 = 1;
	}
	daxie(shi, zero1);
	if (shi != 0)
	{
		cout << "ʰ";
	}
	zero1 = 0;
	//#########################################################
	/*if ((yuan == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi))
	{
		zero1 = 1;
	}*/
	daxie(yuan, 0);
	if (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan)
	{
		cout << "Բ";
	}
	//zero1 = 0;
	//#########################################################
	//�Ǻͷ�
	daxie(jiao, zero1);
	if (jiao != 0)
	{
		cout << "��";
	}
	else
	{
		zero1 = 1;
	}
	//#########################################################
	if (!(shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan || jiao || fen))
	{
		daxie(0, 1);
		cout << "Բ��" << endl;
	}
	else if (!fen)
	{
		cout << "��" << endl;
	}
	else
	{
		if (zero1 && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan))
		{
			daxie(0, 1);
		}
		daxie(fen, 0);
		if (fen != 0)
		{
			cout << "��" << endl;
		}
	}

	return 0;
}
