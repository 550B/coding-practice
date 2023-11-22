#include <stdio.h>
int main()
{
	int n,m=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp>m)m=tmp;
	}
	printf("%d",m);
	return 0;
}
