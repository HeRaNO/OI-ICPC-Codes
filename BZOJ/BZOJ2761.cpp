#include <cstdio>
#include <algorithm>
#define MAXN 50010
using namespace std;

int n, T, R, m, a[MAXN], ori[MAXN], tim[MAXN];
pair <int, int *> b[MAXN];

inline void read(int &x)
{
	x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	x = f ? -x : x;
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);
		m = 0;
		R++;
		for (int i = 1; i <= n; i++)
			read(a[i]), b[i].first = a[i], b[i].second = &a[i];
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++)
		{
			if (b[i].first != b[i - 1].first) ori[++m] = b[i].first;
			*b[i].second = m;
		}
		for (int i = 1; i <= n; i++)
			if (tim[a[i]] != R)
			{
				if (i == 1) printf("%d", ori[a[i]]);
				else printf(" %d", ori[a[i]]);
				tim[a[i]] = R;
			}
		puts("");
	}
	return 0;
}