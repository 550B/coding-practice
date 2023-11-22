#include <stdio.h>
int main()
{
	int x;
	char c;
	scanf("%d %c",&x,&c);
	printf("%d",(x>1000?((x-1000)%500==0?(x-1000)/500*4:((x-1000)/500+1)*4):0)+8+(c=='y'?5:0));
	return 0;
}
