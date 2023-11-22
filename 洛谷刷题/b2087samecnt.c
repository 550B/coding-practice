#include <stdio.h>
int main()
{
	int n,num[101],m,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<n;i++)
	{
		if(m==num[i])cnt++;
	}
	printf("%d",cnt);
	return 0;
}
