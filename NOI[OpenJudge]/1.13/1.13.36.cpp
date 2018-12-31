//Code By HeRaNO
#include <cstdio>
using namespace std;
int main()
{
	int a = 0, b = 0;
	for (int i = 1; i <= 1000; i++)
	{
		int bin = i;
		int cnt0 = 0, cnt1 = 0;
		int tmp;
		while (bin)
		{
			tmp = bin % 2;
			if (tmp)cnt1++;
			else cnt0++;
			bin /= 2;
		}
		if (cnt1 > cnt0) a++;
		else b++;
	}
	printf("%d %d\n", a, b);
	return 0;
}
