#include <stdio.h>
#include <math.h>
int n;
double x,y,dis,t;
int p;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf%d",&x,&y,&p);
		dis=sqrt(x*x+y*y);
		t+=dis*2/50+1.5*p;
	}
	int tmp=t;
//	printf("%.20lf ",t);
//	printf("%d ",tmp);
	if(fabs(t-tmp)<0.0000001)printf("%d",tmp);
	else printf("%d",tmp+1);
	return 0;
} 
