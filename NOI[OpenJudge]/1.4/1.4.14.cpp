//Code By HeRaNO
#include <cstdio>
using namespace std;
int main()
{
	int a = 0, ans = 8;
	char c;
	while (true)
	{
		c = getchar();
		if (c == ' ') break;
		a = a * 10 + c - '0';
	}
	c = getchar();
	if (a > 1000)
	{
		a -= 1000;
		while (a > 0)
		{
			a -= 500;
			ans += 4;
		}
	}
	if (c == 'y') ans += 5;
	printf("%d\n", ans);
	return 0;
}
