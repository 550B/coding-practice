#include <time.h>
#include <stdio.h>
int main()
{
	time_t timer0;
	timer0=time(NULL);
	printf("%lld\n", timer0);
	struct tm* plocaltime = localtime(&timer0);
	printf("\n%d-%d-%d", plocaltime->tm_year + 1900, plocaltime->tm_mon + 1, plocaltime->tm_mday);
	printf(" %d:%d:%d\n",plocaltime->tm_hour,plocaltime->tm_min,plocaltime->tm_sec);
    return 0;
}
