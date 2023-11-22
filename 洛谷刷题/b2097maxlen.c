#include <stdio.h>
int main()
{
	int n,num=0,cnt=0,maxlen=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp!=num)
		{
			num=tmp;
			cnt=0;
		}
		if(tmp==num)
		{
			cnt++;
		}
		if(cnt>maxlen)maxlen=cnt;
	}
	printf("%d",maxlen);
	return 0;
}
