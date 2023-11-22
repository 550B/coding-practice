#include <stdio.h>
#include <math.h>
int main()
{
	double x1,y1,x2,y2,x3,y3;
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
	printf("%.2lf",0.5*(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2));
	return 0;
}
