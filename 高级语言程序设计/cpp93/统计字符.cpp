/*2151974 软件 赵明泽*/
#include <iostream>
using namespace std;

int main()
{
	int j = 0;
	char str[3][128];
	for (int i = 0; i < 3; i++)
	{
		cout << "请输入第" << i + 1 << "行" << endl;
		fgets(str[i], 128, stdin);
	}
	int daxie = 0, xiaoxie = 0, num = 0, space = 0, qita = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 128 && str[i][j] != '\0'; j++)
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
			{
				daxie++;
			}
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
			{
				xiaoxie++;
			}
			else if (str[i][j] >= '0' && str[i][j] <= '9')
			{
				num++;
			}
			else if (str[i][j] == ' ')
			{
				space++;
			}
			else
			{
				qita++;
			}
		}
	}
	cout << "大写 : " << daxie << endl;
	cout << "小写 : " << xiaoxie << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << qita - 3 << endl;

	return 0;
}