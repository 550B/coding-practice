/*2151974 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */
const int L = 0;

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/

	double num;
	int shiyi = 0, yi = 0, qianwan = 0, baiwan = 0, shiwan = 0, wan = 0, qian = 0, bai = 0, shi = 0, yuan = 0, jiao = 0, fen = 0;
	int a = 0;
	int zero1 = 0;
	int ret;

	while (1)
	{
		printf("������[0-100��)֮�������:\n");
		ret = scanf("%lf", &num);

		if (ret == 0)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		if (ret == 1 && (num < 0 || num > 9999999999.99))
		{
			continue;
		}
		break;
	}

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

	strcpy(result, "��д�����:\n");
	//#########################################################
	//ʮ�ڵ���
	if (shiyi != 0)
	{
		strncat(result, &chnstr[shiyi * 2], 2);
		strcat(result, "ʰ");
	}
	//#########################################################
	if (shiyi || yi)
	{
		if (yi != 0)
		{
			strncat(result, &chnstr[yi * 2], 2);
		}
		strcat(result, "��");
	}
	//#########################################################
	//ǧ����
	if ((qianwan == 0) && (shiyi || yi) && baiwan)
	{
		//zero1 = 1;
		strncat(result, &chnstr[L], 2);
	}
	//daxie(qianwan, zero1);
	if (qianwan != 0)
	{
		strncat(result, &chnstr[qianwan * 2], 2);
		strcat(result, "Ǫ");
	}
	//zero1 = 0;
	//#########################################################
	if ((baiwan == 0) && (shiyi || yi || qianwan) && shiwan)
	{
		//zero1 = 1;
		strncat(result, &chnstr[L], 2);
	}
	//daxie(baiwan, zero1);
	if (baiwan != 0)
	{
		strncat(result, &chnstr[baiwan * 2], 2);
		strcat(result, "��");
	}
	//zero1 = 0;
	//#########################################################
	if ((shiwan == 0) && (shiyi || yi || qianwan || baiwan) && wan)
	{
		//zero1 = 1;
		strncat(result, &chnstr[L], 2);
	}
	//daxie(shiwan, zero1);
	if (shiwan != 0)
	{
		strncat(result, &chnstr[shiwan * 2], 2);
		strcat(result, "ʰ");
	}
	//zero1 = 0;
	//#########################################################
	/*if ((wan == 0) && (shiyi || yi || qianwan || baiwan || shiwan))
	{
		zero1 = 1;
	}*/
	//daxie(wan, 0);
	if (qianwan || baiwan || shiwan || wan)
	{
		if (wan != 0)
		{
			strncat(result, &chnstr[wan * 2], 2);
		}
		strcat(result, "��");
	}
	//zero1 = 0;
	//#########################################################
	//ǧ��Բ
	if ((qian == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan) && bai)
	{
		//zero1 = 1;
		strncat(result, &chnstr[L], 2);
	}
	//daxie(qian, zero1);
	if (qian != 0)
	{
		strncat(result, &chnstr[qian * 2], 2);
		strcat(result, "Ǫ");
	}
	//zero1 = 0;
	//#########################################################
	if ((bai == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian) && shi)
	{
		//zero1 = 1;
		strncat(result, &chnstr[L], 2);
	}
	//daxie(bai, zero1);
	if (bai != 0)
	{
		strncat(result, &chnstr[bai * 2], 2);
		strcat(result, "��");
	}
	//zero1 = 0;
	//#########################################################
	if ((shi == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai) && yuan)
	{
		strncat(result, &chnstr[L], 2);
		//zero1 = 1;
	}
	//daxie(shi, zero1);
	if (shi != 0)
	{
		strncat(result, &chnstr[shi * 2], 2);
		strcat(result, "ʰ");
	}
	//zero1 = 0;
	//#########################################################
	/*if ((yuan == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi))
	{
		zero1 = 1;
	}*/
	//daxie(yuan, 0);
	if (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan)
	{
		if (yuan != 0)
		{
			strncat(result, &chnstr[yuan * 2], 2);
		}
		strcat(result, "Բ");
	}
	//zero1 = 0;
	//#########################################################
	//�Ǻͷ�
	//daxie(jiao, zero1);
	if (jiao != 0)
	{
		strncat(result, &chnstr[jiao * 2], 2);
		strcat(result, "��");
	}
	else
	{
		zero1 = 1;
	}
	//#########################################################
	if (!(shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan || jiao || fen))
	{
		//daxie(0, 1);
		strcat(result, "��");
		strcat(result, "Բ��");
	}
	else if (!fen)
	{
		strcat(result, "��");
	}
	else
	{
		if (zero1 && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan))
		{
			strcat(result, "��");
			//daxie(0, 1);
		}
		//daxie(fen, 0);
		if (fen != 0)
		{
			strncat(result, &chnstr[fen * 2], 2);
			strcat(result, "��");
		}
	}

    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}