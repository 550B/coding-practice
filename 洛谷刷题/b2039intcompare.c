#include <stdio.h>
int main()
{
	long long int x,y;
	scanf("%lld%lld",&x,&y);
	if(x>y)printf(">");
	else if(x==y)printf("=");
	else printf("<");
	return 0;
}
