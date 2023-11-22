#include <stdio.h>
int main()
{
	int n,m,num[101][101];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",num[j][i]);
		}
		printf("\n");
	}
	return 0;
}
