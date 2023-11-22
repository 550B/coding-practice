#include <stdio.h>
int main()
{
	int a,b;
	char c;
	scanf("%d%d %c",&a,&b,&c);
	if(c!='+'&&c!='-'&&c!='*'&&c!='/')printf("Invalid operator!");
	else
	{
		if(c=='/'&&b==0)printf("Divided by zero!");
		else if(c=='+')printf("%d",a+b);
		else if(c=='-')printf("%d",a-b);
		else if(c=='*')printf("%d",a*b);
		else if(c=='/')printf("%d",a/b);
	}
	return 0;
}
