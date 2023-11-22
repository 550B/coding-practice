#include <iostream>
using namespace std;
int a[5];
int cnt;
int main()
{
	for(int i=0;i<5;i++)
		cin>>a[i];
	for(int i=0;i<5;i++)
	{
		cnt+=a[i]%3;
		a[i]/=3;
		if(i==0)
		{
			a[4]+=a[i];
			a[1]+=a[i];
		}
		else if(i==4)
		{
			a[3]+=a[i];
			a[0]+=a[i];
		}
		else
		{
			a[i+1]+=a[i];
			a[i-1]+=a[i];
		}
	}
	cout<<a[0];
	for(int i=1;i<5;i++)
		cout<<" "<<a[i];
	cout<<endl;
	cout<<cnt;
	return 0;
}
