#include <stdio.h>
int m,n,cnt;
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(m-tmp<0)cnt++;
		else m-=tmp;
	}
	printf("%d",cnt);
	return 0;
}
