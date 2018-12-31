#include <cstdio>
using namespace std;

const char a[16] =
{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int k, m, M = 1, T, ans, now[4], q, x = 1;

inline int Quick_MOD(int x)
{
	int a = x, b = x, r = 1;
	for (; b; a = (a * a) % M, b >>= 1) if (b & 1) r = (r * a) % M;
	return r;
}

inline void write()
{
	for (int i = m - 1; ~i; i--) putchar(a[now[i]]);
	putchar('\n');
	return ;
}

int main()
{
	scanf("%d %d", &k, &m);
	for (int i = 1; i <= m; i++)
	{
		if (i != m) x *= 10;
		M *= k;
	}
	T = M - 1;
	int r = x;
	while (r)
	{
		now[q] = r % k;
		r /= k;
		++q;
	}
	for (int i = x; i <= T; i++)
	{
		if (Quick_MOD(i) == i)
		{
			write();
			++ans;
		}
		++now[0];
		if (now[0] == k)
		{
			int p = 0;
			now[p] = 0;
			++now[++p];
			while (now[p] == k) now[p] = 0, ++now[++p];
		}
	}
	printf("%d\n", ans);
	return 0;
}