#include <stdio.h>
int main()
{
	int N,age,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&age);
		if(age>=0&&age<=18)cnt1++;
		else if(age>=19&&age<=35)cnt2++;
		else if(age>=36&&age<=60)cnt3++;
		else cnt4++;
	}
	printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n%.2lf%%",(double)(cnt1*100)/(double)(N),(double)(cnt2*100)/(double)(N),(double)(cnt3*100)/(double)(N),(double)(cnt4*100)/(double)(N));
	return 0;
} 
