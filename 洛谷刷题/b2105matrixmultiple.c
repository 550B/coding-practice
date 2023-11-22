#include <stdio.h>
int main()
{
	int n,m,k,a[100][100],b[100][100],ans[100][100]={0};
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<k;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			for(int t=0;t<m;t++)
			{
				ans[i][j]+=a[i][t]*b[t][j];
			}
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
