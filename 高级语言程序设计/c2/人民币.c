/*2151974 ��� ������*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������[0 - 100��)֮�������:\n");

	double num;
	int shiyi = 0, yi = 0, qianwan = 0, baiwan = 0, shiwan = 0, wan = 0, qian = 0, bai = 0, shi = 0, yuan = 0, jiao = 0, fen = 0;
	int a = 0;
	int zero1 = 0;

	scanf("%lf", &num);

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

	printf("��д�����:\n");

	//ʮ�ڵ���
	switch (shiyi)
	{
		case 0:
			break;
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;

	}

	switch (yi)
	{
		case 0:
			break;
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;

	}
	if (shiyi || yi)
	{
		printf("��");
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
			printf("ҼǪ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;

	}

	if (zero1 && baiwan)
	{
		printf("��");
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
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;

	}

	if (zero1 && shiwan)
	{
		printf("��");
		zero1 = 0;
	}
	switch (shiwan)
	{
		case 0:
			if (shiyi || yi || qianwan || baiwan)
			{
				zero1 = 1;
			}
			break;
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;

	}

	if (zero1 && wan)
	{
		printf("��");
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
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;

	}

	if (qianwan || baiwan || shiwan || wan)
	{
		printf("��");
	}

	zero1 = 0;

	//ǧ��Բ
	if (zero1 && qian)
	{
		printf("��");
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
			printf("ҼǪ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;

	}

	if (zero1 && bai)
	{
		printf("��");
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
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;

	}

	if (zero1 && shi)
	{
		printf("��");
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
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;

	}

	if (zero1 && yuan)
	{
		printf("��");
		zero1 = 0;
	}
	switch (yuan)
	{
		case 0:
			break;
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;

	}

	zero1 = 0;

	if (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan)
	{
		printf("Բ");
	}

	//�Ǻͷ�
	switch (jiao)
	{
		case 0:
			zero1 = 1;
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ƽ�");
			break;
		case 9:
			printf("����");
			break;

	}

	if (!(shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan || jiao || fen))
	{
		printf("��Բ��\n");
	}
	else if (!fen)
	{
		printf("��\n");
	}
	else
	{
		if (zero1 && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan))
		{
			printf("��");
		}
		switch (fen)
		{
			case 1:
				printf("Ҽ��\n");
				break;
			case 2:
				printf("����\n");
				break;
			case 3:
				printf("����\n");
				break;
			case 4:
				printf("����\n");
				break;
			case 5:
				printf("���\n");
				break;
			case 6:
				printf("½��\n");
				break;
			case 7:
				printf("���\n");
				break;
			case 8:
				printf("�Ʒ�\n");
				break;
			case 9:
				printf("����\n");
				break;

		}
	}

	return 0;




}