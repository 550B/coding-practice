#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	if(N>0)printf("positive");
	else if(N==0)printf("zero");
	else printf("negative");
	return 0;
}
