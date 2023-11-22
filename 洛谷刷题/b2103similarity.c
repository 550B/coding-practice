#include <stdio.h>
int main()
{
	int m,n,num[101][101],cnt=0;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(tmp==num[i][j])cnt++;
		}
	}
	printf("%.2lf",(double)(cnt*100)/(m*n));
	return 0;
}
