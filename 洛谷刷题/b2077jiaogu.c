#include <stdio.h>
long long int n;
int main()
{
	scanf("%lld",&n);
	while(n!=1)
	{
		if(n%2)
		{
			printf("%lld*3+1=%lld\n",n,n*3+1);
			n=n*3+1;
		}
		else
		{
			printf("%lld/2=%lld\n",n,n/2);
			n/=2;
		}
	}
	printf("End");
	return 0;
} 
