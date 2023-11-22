#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int flag = 0;
	if((a<60&&b>=60&&c>=60)||
	   (a>=60&&b<60&&c>=60)||
	   (a>=60&&b>=60&&c<60))printf("1");
	else printf("0");
	return 0;
}
