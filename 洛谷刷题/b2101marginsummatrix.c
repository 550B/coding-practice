#include <stdio.h>
int main()
{
	int m,n,sum=0;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(i==0||i==m-1||j==0||j==n-1)sum+=tmp;
		}
	}
	printf("%d",sum);
	return 0;
}
