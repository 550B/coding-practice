#include <stdio.h>
int a,b,n;
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	a=a%b;
	for(int i=1;i<n;i++)
	{
		a=a*10%b;
	}
	printf("%d",a*10/b);
	return 0;
}
