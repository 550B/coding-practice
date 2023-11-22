#include <stdio.h>
#include <math.h>
int main()
{
	double xa,ya,xb,yb;
	scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
	printf("%.3lf",sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)));
	return 0;
}
