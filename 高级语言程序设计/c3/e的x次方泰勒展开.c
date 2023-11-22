/*2151974 软件 赵明泽*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	int x;
	double tmp, sum = 1;

	while (true)
	{
		printf("请输入x的值[-10 ~ +65]\n");
		scanf("%d", &x);
		tmp = 1;

		if (x < -10 || x > 65)
		{
			printf("输入非法，请重新输入\n");
			continue;
		}
		else
		{
			for (int i = 1; true; i++)
			{
				tmp = tmp * x;
				tmp = tmp / i;
				if (sum >= 0 && fabs(tmp) < 1e-6)
				{
					break;
				}
				sum += tmp;
			}
			break;
		}
	}

	printf("e^%d=%.10g\n", x, sum);

	return 0;

}