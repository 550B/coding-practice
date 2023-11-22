#include <stdio.h>
int a,b,res=1;
int main()
{
	scanf("%d%d",&a,&b);
	while(b>0)
	{
		if(b&1)
		{
			res=res*a%7;
		}
		b>>=1;
		a=(a*a)%7;
	}
	switch(res)
	{
		case 0:printf("Sunday");break;
		case 1:printf("Monday");break;
		case 2:printf("Tuesday");break;
		case 3:printf("Wednesday");break;
		case 4:printf("Thursday");break;
		case 5:printf("Friday");break;
		case 6:printf("Saturday");break;
	}
	return 0;
}
