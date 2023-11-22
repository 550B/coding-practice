#include <iostream>
#include <iomanip>
using namespace std;
int a,b,res=1;
int main()
{
	cin>>a>>b;
	while(b>0)
	{
		if(b&1)
		{
			res=res*a%1000;
		}
		b>>=1;
		a=(a*a)%1000;
	}
	cout<<setw(3)<<setfill('0')<<res;
	return 0;
}
