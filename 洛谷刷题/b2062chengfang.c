#include <stdio.h>
int main()
{
	int a,n,res=1;
	scanf("%d%d",&a,&n);
	for(int i=n;i>0;i--)
	{
		res*=a;
	}
	printf("%d",res);
	return 0;
}
