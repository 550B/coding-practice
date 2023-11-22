#include <stdio.h>
#include <windows.h>
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=2;i<=max(a,max(b,c));i++)
	{
		if(a%i==b%i&&b%i==c%i&&a%i==c%i)
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}
