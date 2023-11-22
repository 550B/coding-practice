#include <stdio.h>
int ge,shi,bai,qian,n,cnt;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		ge=tmp%10;
		shi=(tmp/10)%10;
		bai=(tmp/100)%10;
		qian=tmp/1000;
		if(ge-qian-bai-shi>0)cnt++;
	}
	printf("%d",cnt);
	return 0;
}
