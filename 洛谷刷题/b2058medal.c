#include <stdio.h>
int main()
{
	int n,gold=0,silver=0,bronze=0,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		gold+=a;silver+=b;bronze+=c;
	}
	sum=gold+silver+bronze;
	printf("%d %d %d %d",gold,silver,bronze,sum);
	return 0;
}
