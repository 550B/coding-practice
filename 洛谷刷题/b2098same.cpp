#include <iostream>
#include <queue>
using namespace std;
int n,cnt[102];
int main()
{
	queue<int>num;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		if(!cnt[p])num.push(p);
		cnt[p]++;
	}
	for(int i=num.size();i>0;i--)
	{
		printf("%d ",num.front());
		num.pop();
	}
	return 0;
}
