#include <iostream>
#include <iomanip>
using namespace std;
const double PRICE[10]={28.9,32.7,45.6,78.0,35.0,86.2,27.8,43.0,56.0,65.0};
int cnt;
double price;
int main()
{
	for(int i=0;i<10;i++)
	{
		cin>>cnt;
		price+=cnt*PRICE[i];
	}
	printf("%.1lf",price);
	return 0;
}
