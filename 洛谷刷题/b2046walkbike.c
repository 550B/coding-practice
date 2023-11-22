#include <stdio.h>
int main()
{
	int d;
	scanf("%d",&d);
	double t1,t2;
	t1=(double)d/1.2;
	t2=(double)d/3.0+50;
	if(t1-t2>1e-5)printf("Bike");
	else if(t2-t1>1e-5)printf("Walk");
	else printf("All");
	return 0;
}
