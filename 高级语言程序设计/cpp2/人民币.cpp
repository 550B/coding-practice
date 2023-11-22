/*2151974 Èí¼þ ÕÔÃ÷Ôó*/
#include <iostream>

using namespace std;
int main()
{
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:" << endl;

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

	cout << "´óÐ´½á¹ûÊÇ:" << endl;

	//Ê®ÒÚµ½ÒÚ
	switch (shiyi)
	{
		case 0:
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈþÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;

	}

	switch (yi)
	{
		case 0:
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;

	}
	if (shiyi || yi)
	{
		cout << "ÒÚ";
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
			cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈþÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;

	}

	if (zero1 && baiwan)
	{
		cout << "Áã";
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
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èþ°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;

	}

	if (zero1 && shiwan)
	{
		cout << "Áã";
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
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈþÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;

	}

	if (zero1 && wan)
	{
		cout << "Áã";
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
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;

	}

	if (qianwan || baiwan || shiwan || wan)
	{
		cout << "Íò";
	}

	zero1 = 0;

	//Ç§µ½Ô²
	if (zero1 && qian)
	{
		cout << "Áã";
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
			cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈþÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;

	}

	if (zero1 && bai)
	{
		cout << "Áã";
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
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èþ°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;

	}

	if (zero1 && shi)
	{
		cout << "Áã";
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
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈþÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;

	}

	if (zero1 && yuan)
	{
		cout << "Áã";
		zero1 = 0;
	}
	switch (yuan)
	{
		case 0:
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;

	}

	zero1 = 0;

	if (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan)
	{
		cout << "Ô²";
	}

	//½ÇºÍ·Ö
	switch (jiao)
	{
		case 0:
			zero1 = 1;
			break;
		case 1:
			cout << "Ò¼½Ç";
			break;
		case 2:
			cout << "·¡½Ç";
			break;
		case 3:
			cout << "Èþ½Ç";
			break;
		case 4:
			cout << "ËÁ½Ç";
			break;
		case 5:
			cout << "Îé½Ç";
			break;
		case 6:
			cout << "Â½½Ç";
			break;
		case 7:
			cout << "Æâ½Ç";
			break;
		case 8:
			cout << "°Æ½Ç";
			break;
		case 9:
			cout << "¾Á½Ç";
			break;

	}

	if (!(shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan || jiao || fen))
	{
		cout << "ÁãÔ²Õû" << endl;
	}
	else if (!fen)
	{
		cout << "Õû" << endl;
	}
	else
	{
		if (zero1 && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan))
		{
			cout << "Áã";
		}
		switch (fen)
		{
			case 1:
				cout << "Ò¼·Ö" << endl;
				break;
			case 2:
				cout << "·¡·Ö" << endl;
				break;
			case 3:
				cout << "Èþ·Ö" << endl;
				break;
			case 4:
				cout << "ËÁ·Ö" << endl;
				break;
			case 5:
				cout << "Îé·Ö" << endl;
				break;
			case 6:
				cout << "Â½·Ö" << endl;
				break;
			case 7:
				cout << "Æâ·Ö" << endl;
				break;
			case 8:
				cout << "°Æ·Ö" << endl;
				break;
			case 9:
				cout << "¾Á·Ö" << endl;
				break;

		}
	}
	
	return 0;

}