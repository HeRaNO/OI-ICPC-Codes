//Code By HeRaNO
#include <cstdio>
using namespace std;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int i, n, hour, minute, second, day, monthth, year;

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d:%d:%d %d.%d.%d", &hour, &minute, &second, &day, &monthth, &year);
		day += (year - 2000) * 365 + (year - 1997) / 4 - (year - 1901) / 100 + (year - 1601) / 400 - 1;
		if (monthth > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			day++;
		for (i = 0; i < monthth - 1; i++)
			day += month[i];
		second = (hour * 3600 + minute * 60 + second) * 125 / 108;
		printf("%d:%d:%d %d.%d.%d\n", second / 10000, (second % 10000) / 100, second % 100, day % 100 + 1, (day / 100) % 10 + 1, day / 1000);
	}
	return 0;
}
