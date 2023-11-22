//Consider the situation that Mr.Smith climbs up stairs.
//He can climb 1 step or 2 steps at one time.
//It costs him 1 calory for climbing 1 step, 
//and 3 calories for climbing 2 steps at one time.
//Q1: Now Mr.Smith needs to climb m steps and he only has n calories.
//How many ways are there for him to climb m steps ?
//Q2: After eating too much, Mr.Smith decides to climb m steps for losing weight.
//Now he also has n calories left.
//At this time, he wants to consume as much calories as possible 
//but no more than n calories.
//How many ways are there for him to climb m steps ?

#include <iostream>
using namespace std;

int recursive(int m, int n)		//recursive function
{
	if (n < m || m <= 0)		//terms of end
	{
		return 0;
	}
	if (m == 1 && n >= 1)		//terms of finding 1 way
	{
		return 1;
	}
	if (m == 2 && n >= 3)		//terms of finding 2 ways
	{
		return 2;
	}
	return recursive(m - 1, n - 1) + recursive(m - 2, n - 3);	//continue
}

int main()
{
	int m, n;			//define 2 nums
	cin >> m >> n;		//cin 2 nums

	if (cin.fail() || m <= 0 || n <= 0 || m > n)	//error detection
	{
		cout << "0";
		return 0;
	}
	cout << recursive(m, n);		//print the result

	return 0;
}