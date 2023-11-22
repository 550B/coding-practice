#include <stdio.h>
int a,b,c,cnt;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int x=0;x<=c/a;x++)
	{
		for(int y=0;a*x+b*y<=c;y++)
		{
			if(a*x+b*y==c)cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
