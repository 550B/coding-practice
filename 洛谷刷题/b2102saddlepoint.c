#include <stdio.h>
int main()
{
	int matrix[5][5],row,col,val;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	for(int i=0;i<5;i++)
	{
		int maxnum=0;
		int p;
		for(int j=0;j<5;j++)
		{
			if(matrix[i][j]>maxnum)
			{
				maxnum=matrix[i][j];
				p=j;
			}
		}
		int minnum=0x7fffffff;
		for(int k=0;k<5;k++)
		{
			if(matrix[k][p]<minnum)
			{
				minnum=matrix[k][p];
			}
		}
		if(maxnum==minnum)
		{
			row=i;
			col=p;
			val=maxnum;
			break;
		}
		else
		{
			row=-1;
			col=-1;
			val=-1;
		}
	}
	if(row!=-1&&col!=-1&&val!=-1)printf("%d %d %d",row+1,col+1,val);
	else printf("not found");
	return 0;
}
