/*2151974 Èí¼ş ÕÔÃ÷Ôó*/
#include <iostream>
using namespace std;

const int NUM = 110;

int main()
{
	int light[NUM] = {};

	for (int i = 1; i <= 100; i++)
	{
		for (int j = i; j <= 100; j += i)
		{
			if (light[j] == 1)
			{
				light[j] = 0;
			}
			else
			{
				light[j] = 1;
			}
		}
	}

	for (int i = 1; i <= 100; i++)
	{
		if (light[i] == 1)
		{
			cout << i;

			if (i != 100)
			{
				cout << " ";
			}
			else
			{
				cout << endl;
			}
		}
	}

	return 0;
}