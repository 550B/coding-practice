/*2151974 ��� ������*/
#include <iostream>

using namespace std;
int main()
{
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

	/*cout << "ʮ��λ : " << shiyi << endl;
	cout << "��λ   : " << yi << endl;
	cout << "ǧ��λ : " << qianwan << endl;
	cout << "����λ : " << baiwan << endl;
	cout << "ʮ��λ : " << shiwan << endl;
	cout << "��λ   : " << wan << endl;
	cout << "ǧλ   : " << qian << endl;
	cout << "��λ   : " << bai << endl;
	cout << "ʮλ   : " << shi << endl;
	cout << "Բ     : " << yuan << endl;
	cout << "��     : " << jiao << endl;
	cout << "��     : " << fen << endl;*/

	cout << "��д�����:" << endl;

	//ʮ�ڵ���
	switch (shiyi)
	{
		case 0:
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;

	}

	switch (yi)
	{
		case 0:
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

	}
	if (shiyi || yi)
	{
		cout << "��";
	}
	//ǧ����
	switch (qianwan)
	{
		case 0:
			if (shiyi || yi)
			{
				zero1 = 1;
			}
			break;
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;

	}

	if (zero1 && baiwan)
	{
		cout << "��";
		zero1 = 0;
	}
	switch (baiwan)
	{
		case 0:
			if (shiyi || yi || qianwan)
			{
				zero1 = 1;
			}
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;

	}

	if (zero1 && shiwan)
	{
		cout << "��";
		zero1 = 0;
	}
	switch (shiwan)
	{
		case 0:
			if (shiyi || yi || qianwan|| baiwan)
			{
				zero1 = 1;
			}
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;

	}

	if (zero1 && wan)
	{
		cout << "��";
		zero1 = 0;
	}
	switch (wan)
	{
		case 0:
			if (shiyi || yi || qianwan || baiwan || shiwan)
			{
				zero1 = 1;
			}
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

	}

	if (qianwan || baiwan || shiwan || wan)
	{
		cout << "��";
	}

	zero1 = 0;

	//ǧ��Բ
	if (zero1 && qian)
	{
		cout << "��";
		zero1 = 0;
	}
	switch (qian)
	{
		case 0:
			if (shiyi || yi || qianwan || baiwan || shiwan || wan)
			{
				zero1 = 1;
			}
			break;
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;

	}

	if (zero1 && bai)
	{
		cout << "��";
		zero1 = 0;
	}
	switch (bai)
	{
		case 0:
			if (shiyi || yi || qianwan || baiwan || shiwan || wan || qian)
			{
				zero1 = 1;
			}
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;

	}

	if (zero1 && shi)
	{
		cout << "��";
		zero1 = 0;
	}
	switch (shi)
	{
		case 0:
			if (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai)
			{
				zero1 = 1;
			}
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;

	}

	if (zero1 && yuan)
	{
		cout << "��";
		zero1 = 0;
	}
	switch (yuan)
	{
		case 0:
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

	}

	zero1 = 0;

	if (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan)
	{
		cout << "Բ";
	}

	//�Ǻͷ�
	switch (jiao)
	{
		case 0:
			zero1 = 1;
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ƽ�";
			break;
		case 9:
			cout << "����";
			break;

	}

	if (!(shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan || jiao || fen))
	{
		cout << "��Բ��" << endl;
	}
	else if (!fen)
	{
		cout << "��" << endl;
	}
	else
	{
		if (zero1 && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan))
		{
			cout << "��";
		}
		switch (fen)
		{
			case 1:
				cout << "Ҽ��" << endl;
				break;
			case 2:
				cout << "����" << endl;
				break;
			case 3:
				cout << "����" << endl;
				break;
			case 4:
				cout << "����" << endl;
				break;
			case 5:
				cout << "���" << endl;
				break;
			case 6:
				cout << "½��" << endl;
				break;
			case 7:
				cout << "���" << endl;
				break;
			case 8:
				cout << "�Ʒ�" << endl;
				break;
			case 9:
				cout << "����" << endl;
				break;

		}
	}
	
	return 0;

}