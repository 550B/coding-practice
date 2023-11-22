#include <stdio.h>
long long int m;
int k,cnt;
int main()
{
	scanf("%lld%d",&m,&k);
	while(m>0)
	{
		if(m%10==3)cnt++;
		m/=10;
	}
	if(cnt==k)printf("YES");
	else printf("NO");
	return 0;
}
