#include <iostream>
using namespace std;
int main()
{
	int N;
	bool light[5001]={true};
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;i*j<=N;j++)
		{
			light[i*j]=!light[i*j];
		}
	}
	for(int i=1;i<=N;i++)
	{
		if(light[i])cout<<i<<" ";
	}
	return 0;
}
