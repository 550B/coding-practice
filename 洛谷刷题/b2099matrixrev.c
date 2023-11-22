#include <stdio.h>
int main()
{
	int matrix[5][5],m,n;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	
	///////////////////////////////
	/*for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}*/
	////////////////////////////////
	
	scanf("%d%d",&m,&n);
	for(int i=0;i<5;i++)
	{
		int tmp=matrix[m-1][i];
		matrix[m-1][i]=matrix[n-1][i];
		matrix[n-1][i]=tmp;
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
