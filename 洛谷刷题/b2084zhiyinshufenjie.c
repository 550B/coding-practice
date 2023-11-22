#include <stdio.h>
int n,maxi,t;
int main()
{
	scanf("%d",&n);
	t=n;
	for(int i=2;i<t/2;i++)
	{
		while(n%i==0)
		{
			if(i>maxi)maxi=i;
			n/=i;
		}
	}
	printf("%d",maxi);
	return 0;
}
