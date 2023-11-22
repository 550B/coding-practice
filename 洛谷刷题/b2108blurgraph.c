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
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0||i==n-1||j==0||j==m-1)
			{
				printf("%d ",num[i][j]);
			}
			else
			{
				printf("%d ",((num[i][j]+num[i-1][j]+num[i+1][j]+num[i][j+1]+num[i][j-1])/5.0-(num[i][j]+num[i-1][j]+num[i+1][j]+num[i][j+1]+num[i][j-1])/5)>=0.5?(num[i][j]+num[i-1][j]+num[i+1][j]+num[i][j+1]+num[i][j-1])/5+1:(num[i][j]+num[i-1][j]+num[i+1][j]+num[i][j+1]+num[i][j-1])/5);
			}
		}
		printf("\n");
	}
	return 0;
}
