#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	double delta = b*b-4*a*c;
	if(delta<0)printf("No answer!");
	else if(delta<1e-9)printf("x1=x2=%.5lf",(-b+sqrt(delta))/(2*a));
	else
	{
		double x1 = (-b+sqrt(delta))/(2*a),x2=(-b-sqrt(delta))/(2*a);
		printf("x1=%.5lf;x2=%.5lf",x1>x2?x2:x1,x1>x2?x1:x2);
	}
	return 0;
}
