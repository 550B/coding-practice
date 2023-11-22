#include <stdio.h>
int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	if(a-(int)((a/b))*b<1e-5)printf("%lf",a-(int)((a/b-1))*b);
	else if(a-(int)((a/b))*b-b>=1e-5)printf("%lf",a-(int)((a/b+1))*b);
	else printf("%lf",a-(int)((a/b))*b);
	return 0;
}
