#include <stdio.h>
long long int h;
double dis,ht;
int main()
{
	scanf("%lld",&h);
	ht=h;
	for(int i=0;i<9;i++)
	{
		dis+=ht;
		ht/=2;
	}
	printf("%lf\n%lf",dis+h,ht/2);
	return 0;
}
