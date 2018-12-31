#include <cstdio>
using namespace std;

int n, x, sum, mx;

inline int max(int a, int b)
{
	return a > b ? a : b;
}
inline int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d", &n);
	if (n < 3) return puts("-1"), 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		sum += x;
		mx = max(mx, x);
		if (mx * 2 < sum)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
