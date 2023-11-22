#include <stdio.h>
int min(int a,int b)
{
	return a>b?b:a;
}
int main()
{
	int N,i,j,tmp;
	scanf("%d%d%d",&N,&i,&j);
	for(int k=1;k<=N;k++)
	{
		printf("(%d,%d) ",i,k);
	}
	printf("\n");
	for(int k=1;k<=N;k++)
	{
		printf("(%d,%d) ",k,j);
	}
	printf("\n");
	tmp=min(i,j);
	int a,b;
	for(a=i-tmp+1,b=j-tmp+1;a<=N&&b<=N;a++,b++)
	{
		printf("(%d,%d) ",a,b);
	}
	printf("\n");
	for(a=(i+j-1)>N?N:(i+j-1),b=(j-a+i);a>=1&&b<=N;a--,b++)
	{
		printf("(%d,%d) ",a,b);
	}
	return 0;
}
