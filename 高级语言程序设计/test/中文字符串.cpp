#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string chn = { "��Ҽ��������½��ƾ�" };
	string er = { "������,��.��/��<��>��?��:��;��'��[Ҫ]��{��}��|������!!ENGLISH@#$%++" };
	string birthday;
	const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
	char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */


	cout << "         1         2         3         4         5         6" << endl;
	cout << "123456789012345678901234567890123456789012345678901234567890123456789" << endl;

	//cout << chn[2] << endl;
	//birthday[0] = chn[0];
	//birthday[4] = chn[1];
	//birthday[7] = chn[2];
	//strcat(birthday, chn);
	/*cout << (int)chn[0] << " " << (int)chn[1] << endl;
	cout << (int)chn[2] << " " << (int)chn[3] << endl;
	cout << (int)chn[4] << " " << (int)chn[5] << endl;
	cout << (int)chn[6] << " " << (int)chn[7] << endl;
	cout << (int)chn[8] << " " << (int)chn[9] << endl;
	cout << (int)chn[10] << " " << (int)chn[11] << endl;
	cout << (int)chn[12] << " " << (int)chn[13] << endl;
	cout << (int)chn[14] << " " << (int)chn[15] << endl;
	cout << (int)chn[16] << " " << (int)chn[17] << endl;
	cout << (int)chn[18] << " " << (int)chn[19] << endl;*/
	//cout << (int)chn[0] << " " << (int)chn[1] << endl;
	//cout << (int)chn[0] << " " << (int)chn[1] << endl;
	//cout << (int)chn[0] << " " << (int)chn[1] << endl;
	//cout << (int)chn[0] << " " << (int)chn[1] << endl;

	//result[0] = chnstr[0];
	//result[1] = chnstr[1];
	//cout << result;

	//strcat(result, "��д�����:\n");
	char tmp[13] = "��д�����:\n";
	strcpy(result, tmp);
	strncat(result, chnstr,2);
	strncat(result, &chnstr[2], 2);
	strcat(result, "ʰ");
	cout << result;

	//cout << birthday << endl;
	//cout << chn << endl;
	//cout << er << endl;

	return 0;
}