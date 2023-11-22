#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

double fun(double x1, double x2)
{
	cout << setiosflags(ios::fixed) << setprecision(3);

	if (fabs(2 * x1 * x1 * x1 - 9 * x1 * x1 + 12 * x1 - 3) < 1e-6)
	{
		cout << "x=";
		return x1;
	}
	if (fabs(2 * x2 * x2 * x2 - 9 * x2 * x2 + 12 * x2 - 3) < 1e-6)
	{
		cout << "x=";
		return x2;
	}
	//2 * x * x * x - 9 * x * x + 12 * x - 3
	//(x1 + (x2 - x1) / 2.0)
	//(x2 - (x2 - x1) / 2.0)
	if (2 * (x1 + (x2 - x1) / 2.0) * (x1 + (x2 - x1) / 2.0) * (x1 + (x2 - x1) / 2.0) - 9 * (x1 + (x2 - x1) / 2.0) * (x1 + (x2 - x1) / 2.0) + 12 * (x1 + (x2 - x1) / 2.0) - 3 * ( 2 * x2 * x2 * x2 - 9 * x2 * x2 + 12 * x2 - 3 ) > 0)
	{
		x2 = x2 - (x2 - x1) / 2.0;
	}
	else if (2 * (x2 - (x2 - x1) / 2.0) * (x2 - (x2 - x1) / 2.0) * (x2 - (x2 - x1) / 2.0) - 9 * (x2 - (x2 - x1) / 2.0) * (x2 - (x2 - x1) / 2.0) + 12 * (x2 - (x2 - x1) / 2.0) - 3 * (2 * x1 * x1 * x1 - 9 * x1 * x1 + 12 * x1 - 3) > 0)
	{
		x1 = x1 + (x2 - x1) / 2.0;
	}
	fun(x1, x2);
}

int main()
{
	fun(0, 1);
	cout << endl;
	return 0;
}