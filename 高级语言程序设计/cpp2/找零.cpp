/*2151974 ��� ������*/
#include <iostream>

using namespace std;
int main()
{
	cout << "����������ֵ��" << endl;

	double temp;
	int num, sum;
	int yuan50 = 0, yuan20 = 0, yuan10 = 0, yuan5 = 0, yuan1 = 0, jiao5 = 0, jiao1 = 0, fen5 = 0, fen2 = 0, fen1 = 0;

	cin >> temp;

	num = (int)((temp + 0.00000000001) * 100);

	if ((num - 5000)>0)
	{
		yuan50 = 1;
		num = num - 5000;
		yuan20 = num / 2000;
		if (num / 2000)
		{
			num = num - yuan20 * 2000;
			yuan10 = num / 1000;
			if (num / 1000)
			{
				num = num - yuan10 * 1000;
				yuan5 = num / 500;
				if (num / 500)
				{
					num = num - yuan5 * 500;
					yuan1 = num / 100;
					

				}
				else if (num == 500)
				{
					num = num - 500;
					yuan5 = 1;

				}
				else
				{
					yuan1 = num / 100;
				}

			}
			else if (num == 1000)
			{
				num = num - 1000;
				yuan10 = 1;

			}
			else
			{
				yuan5 = num / 500;
				if (num / 500)
				{
					num = num - yuan5 * 500;
					yuan1 = num / 100;


				}
				else if (num == 500)
				{
					num = num - 500;
					yuan5 = 1;

				}
				else
				{
					yuan1 = num / 100;
				}

			}

		}
		else if (num == 2000)
		{
			num = num - 2000;
			yuan20 = 1;
		}
		else
		{
			yuan10 = num / 1000;
			if (num / 1000)
			{
				num = num - yuan10 * 1000;
				yuan5 = num / 500;
				if (num / 500)
				{
					num = num - yuan5 * 500;
					yuan1 = num / 100;


				}
				else if (num == 500)
				{
					num = num - 500;
					yuan5 = 1;

				}
				else
				{
					yuan1 = num / 100;
				}

			}
			else if (num == 1000)
			{
				num = num - 1000;
				yuan10 = 1;

			}
			else
			{
				yuan5 = num / 500;
				if (num / 500)
				{
					num = num - yuan5 * 500;
					yuan1 = num / 100;


				}
				else if (num == 500)
				{
					num = num - 500;
					yuan5 = 1;

				}
				else
				{
					yuan1 = num / 100;
				}

			}

		}

	}
	else if (num == 5000)
	{
		num = num - 5000;
		yuan50 = 1;
	}
	else
	{
		yuan50 = 0;
		yuan20 = num / 2000;
		if (num / 2000)
		{
			num = num - yuan20 * 2000;
			yuan10 = num / 1000;
			if (num / 1000)
			{
				num = num - yuan10 * 1000;
				yuan5 = num / 500;
				if (num / 500)
				{
					num = num - yuan5 * 500;
					yuan1 = num / 100;


				}
				else if (num == 500)
				{
					num = num - 500;
					yuan5 = 1;

				}
				else
				{
					yuan1 = num / 100;
				}

			}
			else if (num == 1000)
			{
				num = num - 1000;
				yuan10 = 1;

			}
			else
			{
				yuan5 = num / 500;
				if (num / 500)
				{
					num = num - yuan5 * 500;
					yuan1 = num / 100;


				}
				else if (num == 500)
				{
					num = num - 500;
					yuan5 = 1;

				}
				else
				{
					yuan1 = num / 100;
				}

			}

		}
		else if (num == 2000)
		{
			num = num - 2000;
			yuan20 = 1;
		}
		else
		{
			yuan10 = num / 1000;
			if (num / 1000)
			{
				num = num - yuan10 * 1000;
				yuan5 = num / 500;
				if (num / 500)
				{
					num = num - yuan5 * 500;
					yuan1 = num / 100;


				}
				else if (num == 500)
				{
					num = num - 500;
					yuan5 = 1;

				}
				else
				{
					yuan1 = num / 100;
				}

			}
			else if (num == 1000)
			{
				num = num - 1000;
				yuan10 = 1;

			}
			else
			{
				yuan5 = num / 500;
				if (num / 500)
				{
					num = num - yuan5 * 500;
					yuan1 = num / 100;


				}
				else if (num == 500)
				{
					num = num - 500;
					yuan5 = 1;

				}
				else
				{
					yuan1 = num / 100;
				}

			}

		}

	}

	num = num - yuan1 * 100;

	if ((num - 50) > 0)
	{
		jiao5 = 1;
		num = num - 50;
		jiao1 = num / 10;

	}
	else if (num == 50)
	{
		num = num - 50;
		jiao5 = 1;
	}
	else
	{
		jiao5 = 0;
		jiao1 = num / 10;

	}

	num = num - jiao1 * 10;

	if ((num - 5) > 0)
	{
		fen5 = 1;
		num = num - 5;
		fen2 = num / 2;
		if (num / 2)
		{
			num = num - fen2 * 2;
			fen1 = num;

		}
		else if (num == 2)
		{
			num = num - 2;
			fen2 = 1;
		}
		else
		{
			fen1 = num;

		}

	}
	else if (num == 5)
	{
		num = num - 5;
		fen5 = 1;

	}
	else
	{
		fen5 = 0;
		fen2 = num / 2;
		if (num / 2)
		{
			num = num - fen2 * 2;
			fen1 = num;

		}
		else if (num == 2)
		{
			num = num - 2;
			fen2 = 1;
		}
		else
		{
			fen1 = num;

		}
	}
	
	/*cout << setiosflags(ios::fixed) << setprecision(20);*/
	/*cout << yuan50 << endl << yuan20 << endl << yuan10 << endl << yuan5 << endl << yuan1 << endl << jiao5 << endl << jiao1 << endl << fen5 << endl << fen2 << endl << fen1 << endl;
	cout << num ;*/

	sum = yuan50 + yuan20 + yuan10 + yuan5 + yuan1 + jiao5 + jiao1 + fen5 + fen2 + fen1;

	cout << "��" << sum << "�����㣬�������£�" << endl;
	if (yuan50)
	{
		cout << "50Ԫ : " << yuan50 << "��" << endl;
	}
	if (yuan20)
	{
		cout << "20Ԫ : " << yuan20 << "��" << endl;
	}
	if (yuan10)
	{
		cout << "10Ԫ : " << yuan10 << "��" << endl;
	}
	if (yuan5)
	{
		cout << "5Ԫ  : " << yuan5 << "��" << endl;
	}
	if (yuan1)
	{
		cout << "1Ԫ  : " << yuan1 << "��" << endl;
	}
	if (jiao5)
	{
		cout << "5��  : " << jiao5 << "��" << endl;
	}
	if (jiao1)
	{
		cout << "1��  : " << jiao1 << "��" << endl;
	}
	if (fen5)
	{
		cout << "5��  : " << fen5 << "��" << endl;
	}
	if (fen2)
	{
		cout << "2��  : " << fen2 << "��" << endl;
	}
	if (fen1)
	{
		cout << "1��  : " << fen1 << "��" << endl;
	}
	

	return 0;

}