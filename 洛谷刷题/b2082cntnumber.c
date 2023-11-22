#include <stdio.h>
int l,r,cnt;
int main()
{
	scanf("%d%d",&l,&r);
	for(int i=l;i<=r;i++)
	{
		if(i>1&&i<10&&i==2)cnt++;
		else if(i>10&&i<100)
		{
			if(i%10==2)cnt++;
			if((i/10)%10==2)cnt++;
		}
		else if(i>100&&i<1000)
		{
			if(i%10==2)cnt++;
			if((i/10)%10==2)cnt++;
			if((i/100)%10==2)cnt++;
		}
		else if(i>1000&&i<10000)
		{
			if(i%10==2)cnt++;
			if((i/10)%10==2)cnt++;
			if((i/100)%10==2)cnt++;
			if((i/1000)%10==2)cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
