/*2151974 Èí¼þ ÕÔÃ÷Ôó*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("ÇëÊäÈë[0 - 100ÒÚ)Ö®¼äµÄÊý×Ö:\n");

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

	/*cout << "Ê®ÒÚÎ» : " << shiyi << endl;
	cout << "ÒÚÎ»   : " << yi << endl;
	cout << "Ç§ÍòÎ» : " << qianwan << endl;
	cout << "°ÙÍòÎ» : " << baiwan << endl;
	cout << "Ê®ÍòÎ» : " << shiwan << endl;
	cout << "ÍòÎ»   : " << wan << endl;
	cout << "Ç§Î»   : " << qian << endl;
	cout << "°ÙÎ»   : " << bai << endl;
	cout << "Ê®Î»   : " << shi << endl;
	cout << "Ô²     : " << yuan << endl;
	cout << "½Ç     : " << jiao << endl;
	cout << "·Ö     : " << fen << endl;*/

	printf("´óÐ´½á¹ûÊÇ:\n");

	//Ê®ÒÚµ½ÒÚ
	switch (shiyi)
	{
		case 0:
			break;
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈþÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;

	}

	switch (yi)
	{
		case 0:
			break;
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èþ");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;

	}
	if (shiyi || yi)
	{
		printf("ÒÚ");
	}
	//Ç§Íòµ½Íò
	switch (qianwan)
	{
		case 0:
			if (shiyi || yi)
			{
				zero1 = 1;
			}
			break;
		case 1:
			printf("Ò¼Çª");
			break;
		case 2:
			printf("·¡Çª");
			break;
		case 3:
			printf("ÈþÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
			break;

	}

	if (zero1 && baiwan)
	{
		printf("Áã");
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
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èþ°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;

	}

	if (zero1 && shiwan)
	{
		printf("Áã");
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
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈþÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;

	}

	if (zero1 && wan)
	{
		printf("Áã");
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
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èþ");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;

	}

	if (qianwan || baiwan || shiwan || wan)
	{
		printf("Íò");
	}

	zero1 = 0;

	//Ç§µ½Ô²
	if (zero1 && qian)
	{
		printf("Áã");
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
			printf("Ò¼Çª");
			break;
		case 2:
			printf("·¡Çª");
			break;
		case 3:
			printf("ÈþÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
			break;

	}

	if (zero1 && bai)
	{
		printf("Áã");
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
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èþ°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;

	}

	if (zero1 && shi)
	{
		printf("Áã");
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
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈþÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;

	}

	if (zero1 && yuan)
	{
		printf("Áã");
		zero1 = 0;
	}
	switch (yuan)
	{
		case 0:
			break;
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èþ");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;

	}

	zero1 = 0;

	if (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan)
	{
		printf("Ô²");
	}

	//½ÇºÍ·Ö
	switch (jiao)
	{
		case 0:
			zero1 = 1;
			break;
		case 1:
			printf("Ò¼½Ç");
			break;
		case 2:
			printf("·¡½Ç");
			break;
		case 3:
			printf("Èþ½Ç");
			break;
		case 4:
			printf("ËÁ½Ç");
			break;
		case 5:
			printf("Îé½Ç");
			break;
		case 6:
			printf("Â½½Ç");
			break;
		case 7:
			printf("Æâ½Ç");
			break;
		case 8:
			printf("°Æ½Ç");
			break;
		case 9:
			printf("¾Á½Ç");
			break;

	}

	if (!(shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan || jiao || fen))
	{
		printf("ÁãÔ²Õû\n");
	}
	else if (!fen)
	{
		printf("Õû\n");
	}
	else
	{
		if (zero1 && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan))
		{
			printf("Áã");
		}
		switch (fen)
		{
			case 1:
				printf("Ò¼·Ö\n");
				break;
			case 2:
				printf("·¡·Ö\n");
				break;
			case 3:
				printf("Èþ·Ö\n");
				break;
			case 4:
				printf("ËÁ·Ö\n");
				break;
			case 5:
				printf("Îé·Ö\n");
				break;
			case 6:
				printf("Â½·Ö\n");
				break;
			case 7:
				printf("Æâ·Ö\n");
				break;
			case 8:
				printf("°Æ·Ö\n");
				break;
			case 9:
				printf("¾Á·Ö\n");
				break;

		}
	}

	return 0;




}