#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,maxi,mini;
	double num[301];
	double avg=0,mis=0,maxnum=0,minnum=99999999.9,sum=0,maxmis=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		sum+=num[i];
		if(num[i]>maxnum)
		{
			maxnum=num[i];
			maxi=i;
		}
		if(num[i]<minnum)
		{
			minnum=num[i];
			mini=i;
		}
	}
	sum=sum-num[maxi]-num[mini];
	num[maxi]=num[mini]=0;
	avg=sum/(n-2);
	for(int i=0;i<n;i++)
	{
		if(i==maxi||i==mini)continue;
		mis=fabs(num[i]-avg);
		if(mis>maxmis)maxmis=mis;
	}
	printf("%.2lf %.2lf",avg,maxmis);
	return 0;
}
