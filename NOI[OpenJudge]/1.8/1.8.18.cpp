//Code By HeRaNO
#include <cstdio>
using namespace std;
int a, n, t, x, y;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		t = 0;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a);
			if (!a) t++;
		}
		if (t > y) y = t;
		if (t) x++;
	}
	printf("%d", (x - 2) * (y - 2));
	return 0;
}
