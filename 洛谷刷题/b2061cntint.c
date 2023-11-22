#include <stdio.h>
int main()
{
	int k;
	int one=0,five=0,ten=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp==1)one++;
		else if(tmp==5)five++;
		else if(tmp==10)ten++;
	}
	printf("%d\n%d\n%d",one,five,ten);
	return 0;
}
