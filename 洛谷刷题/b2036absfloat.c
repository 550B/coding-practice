#include <stdio.h>
int main()
{
	float n;
	scanf("%f",&n);
	if(n<=-1e-6)printf("%.2f",-n);
	else printf("%.2f",n);
	return 0;
}
