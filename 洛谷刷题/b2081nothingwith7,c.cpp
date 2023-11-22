#include <stdio.h>
int n,res;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(i%7&&i%10!=7&&(i/10)%10!=7)res+=i*i;
	printf("%d",res);
	return 0;
}
