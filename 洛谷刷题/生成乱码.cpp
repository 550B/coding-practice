#include <iostream>
using namespace std;
int main()
{
	char c;
	for(int j=0;j<100;j++)
	{
		for(int i=0;i<100;i++)
		{
		c=rand()%1000;
		if(c!=7)cout<<c;
		}
	cout<<endl;
	}
	return 0;
}
