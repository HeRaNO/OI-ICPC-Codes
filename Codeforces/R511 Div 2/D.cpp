#include <cstdio>
using namespace std;

long long ans, n, m;

inline void read(long long &x)
{
	x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch - getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3LL) + (x << 1LL) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	read(n);
	read(m);
	if (n > m)
	{
		int t = m;
		m = n;
		n = t;
	}
	if (n == 1) printf("%I64d\n", m / 6 * 6 + (m % 6 < 3 ? 0 : m % 6 - 3) * 2);
	else if (n == 2)
	{
		if (m == 2) puts("0");
		else if (m == 3 || m == 7) printf("%I64d\n", n * m - 2);
		else printf("%I64d\n", n * m);
	}
	else printf("%I64d\n", n * m - (n * m) % 2);
	return 0;
}