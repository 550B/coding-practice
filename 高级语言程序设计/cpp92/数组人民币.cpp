/*2151974 软件 赵明泽*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */
const int L = 0;
const int Y = 1;

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/

	double num;
	int shiyi = 0, yi = 0, qianwan = 0, baiwan = 0, shiwan = 0, wan = 0, qian = 0, bai = 0, shi = 0, yuan = 0, jiao = 0, fen = 0;
	int a = 0;
	int zero1 = 0;

	while (1)
	{
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> num;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(99999, '\n');
			continue;
		}
		if (num < 0 || num > 9999999999.99)
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

	result += "大写结果是:\n";
	//#########################################################
	//十亿到亿
	if (shiyi != 0)
	{
		result += chnstr[shiyi * 2];
		result += chnstr[shiyi * 2 + 1];
		result += "拾";
	}
	//#########################################################
	if (shiyi || yi)
	{
		if (yi != 0)
		{
			result += chnstr[yi * 2];
			result += chnstr[yi * 2 + 1];
		}
		result += "亿";
	}
	//#########################################################
	//千万到万
	if ((qianwan == 0) && (shiyi || yi) && baiwan)
	{
		//zero1 = 1;
		result += chnstr[L];
		result += chnstr[Y];
	}
	//daxie(qianwan, zero1);
	if (qianwan != 0)
	{
		result += chnstr[qianwan * 2];
		result += chnstr[qianwan * 2 + 1];
		result += "仟";
	}
	//zero1 = 0;
	//#########################################################
	if ((baiwan == 0) && (shiyi || yi || qianwan) && shiwan)
	{
		//zero1 = 1;
		result += chnstr[L];
		result += chnstr[Y];
	}
	//daxie(baiwan, zero1);
	if (baiwan != 0)
	{
		result += chnstr[baiwan * 2];
		result += chnstr[baiwan * 2 + 1];
		result += "佰";
	}
	//zero1 = 0;
	//#########################################################
	if ((shiwan == 0) && (shiyi || yi || qianwan || baiwan) && wan)
	{
		//zero1 = 1;
		result += chnstr[L];
		result += chnstr[Y];
	}
	//daxie(shiwan, zero1);
	if (shiwan != 0)
	{
		result += chnstr[shiwan * 2];
		result += chnstr[shiwan * 2 + 1];
		result += "拾";
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
			result += chnstr[wan * 2];
			result += chnstr[wan * 2 + 1];
		}
		result += "万";
	}
	//zero1 = 0;
	//#########################################################
	//千到圆
	if ((qian == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan) && bai)
	{
		//zero1 = 1;
		result += chnstr[L];
		result += chnstr[Y];
	}
	//daxie(qian, zero1);
	if (qian != 0)
	{
		result += chnstr[qian * 2];
		result += chnstr[qian * 2 + 1];
		result += "仟";
	}
	//zero1 = 0;
	//#########################################################
	if ((bai == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian) && shi)
	{
		//zero1 = 1;
		result += chnstr[L];
		result += chnstr[Y];
	}
	//daxie(bai, zero1);
	if (bai != 0)
	{
		result += chnstr[bai * 2];
		result += chnstr[bai * 2 + 1];
		result += "佰";
	}
	//zero1 = 0;
	//#########################################################
	if ((shi == 0) && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai) && yuan)
	{
		result += chnstr[L];
		result += chnstr[Y];
		//zero1 = 1;
	}
	//daxie(shi, zero1);
	if (shi != 0)
	{
		result += chnstr[shi * 2];
		result += chnstr[shi * 2 + 1];
		result += "拾";
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
			result += chnstr[yuan * 2];
			result += chnstr[yuan * 2 + 1];
		}
		result += "圆";
	}
	//zero1 = 0;
	//#########################################################
	//角和分
	//daxie(jiao, zero1);
	if (jiao != 0)
	{
		result += chnstr[jiao * 2];
		result += chnstr[jiao * 2 + 1];
		result += "角";
	}
	else
	{
		zero1 = 1;
	}
	//#########################################################
	if (!(shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan || jiao || fen))
	{
		//daxie(0, 1);
		result += "零";
		result += "圆整";
	}
	else if (!fen)
	{
		result += "整";
	}
	else
	{
		if (zero1 && (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi || yuan))
		{
			result += "零";
			//daxie(0, 1);
		}
		//daxie(fen, 0);
		if (fen != 0)
		{
			result += chnstr[fen * 2];
			result += chnstr[fen * 2 + 1];
			result += "分";
		}
	}

    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}