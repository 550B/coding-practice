#include <stdio.h>
int main()
{
	int n,a[1001],b,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b);
		ans+=b*a[i];
	}
	printf("%d",ans);
	return 0;
}
