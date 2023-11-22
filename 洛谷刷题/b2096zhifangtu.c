#include <stdio.h>
int n,maxnum;
int num[100002];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		if(p>maxnum)maxnum=p;
		num[p]++;
	}
	for(int i=0;i<=maxnum;i++)
	{
		printf("%d\n",num[i]);
	}
	return 0;
}
