#include <stdio.h>
int main()
{
	int N,maxnum=0,sum=0,cnt=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp>maxnum)
		{
			maxnum=tmp;
			cnt=0;
		}
		if(tmp==maxnum)
		{
			cnt++;
		}
		sum+=tmp;
	}
	printf("%d",sum-maxnum*cnt);
	return 0;
}
