#include <stdio.h>
int a,b,f;
char c;
int main()
{
	scanf("%d%d %c%d",&a,&b,&c,&f);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(i==1||i==a)printf("%c",c);
			else if(f)printf("%c",c);
			else if(j==1||j==b)printf("%c",c);
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
