#include <cstdio>
#define MAXN 100010
using namespace std;

int n, x, a[MAXN];

inline int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}
inline int abs(int a)
{
	return a < 0 ? -a : a;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	read(n);
	read(x);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		a[i] = abs(a[i] - x);
	}
	for (int i = 2; i <= n; i++) a[i] = gcd(a[i], a[i - 1]);
	printf("%d\n", a[n]);
	return 0;
}