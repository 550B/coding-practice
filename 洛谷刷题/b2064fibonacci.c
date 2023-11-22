#include <stdio.h>
#define MAX 31
int fib[MAX];
int main()
{
	fib[1]=1;fib[2]=1;
	for(int i=3;i<=30;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	//printf("%d",fib[30]);
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		printf("%d\n",fib[a]);
	}
	return 0;
}
