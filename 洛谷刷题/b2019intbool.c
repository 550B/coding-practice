#include <stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	bool b = (bool)a;
	a = b;
	printf("%d",a);
	return 0;
}
