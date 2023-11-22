/*2151974 软件 赵明泽*/
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：daxie
  功    能：输出大写的0~9
  输入参数：num,flag_of_zero
  返 回 值：无
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	cout << "请输入[0-100亿)之间的数字:" << endl;

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

	cout << "大写结果是:" << endl;
	//#########################################################
	//十亿到亿
	daxie(shiyi, zero1);
	if (shiyi != 0)
	{
		cout << "拾";
	}
	//#########################################################
	daxie(yi, zero1);
	if (shiyi || yi)
	{
		cout << "亿";
	}
	//#########################################################
	//千万到万
	if ((qianwan == 0) && (shiyi || yi) && baiwan)
	{
		zero1 = 1;
	}
	daxie(qianwan, zero1);
	if (qianwan != 0)
	{
		cout << "仟";
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
		cout << "佰";
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
		cout << "拾";
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
		cout << "万";
	}
	//zero1 = 0;
	//#########################################################
	//千到圆
	if ((qian == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan) && bai)
	{
		zero1 = 1;
	}
	daxie(qian, zero1);
	if (qian != 0)
	{
		cout << "仟";
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
		cout << "佰";
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
		cout << "拾";
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
		cout << "圆";
	}
	//zero1 = 0;
	//#########################################################
	//角和分
	daxie(jiao, zero1);
	if (jiao != 0)
	{
		cout << "角";
	}
	else
	{
		zero1 = 1;
	}
	//#########################################################
	if (!(shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan || jiao || fen))
	{
		daxie(0, 1);
		cout << "圆整" << endl;
	}
	else if (!fen)
	{
		cout << "整" << endl;
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
			cout << "分" << endl;
		}
	}

	return 0;
}
