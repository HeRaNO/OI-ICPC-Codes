#include <stdio.h>

long long n, m;

inline void read(long long &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	while (true)
	{
		read(n);
		read(m);
		if (!n) break;
		printf("%lld\n", n * m - ((n - 1) / 3 + 1) * ((m - 1) / 3 + 1));
	}
	return 0;
}