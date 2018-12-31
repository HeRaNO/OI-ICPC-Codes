#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 100001
#define MAXB 317
using namespace std;

struct Bookshelf
{
	bool opt;
	int a, b, p;
};

Bookshelf c[MAXN];
int cnt[MAXN << 1][MAXB];
int n, T, m, opt, block_num, pt, a[MAXN], ori[MAXN << 1], pos[MAXN];
pair <int, int *> b[MAXN << 1];

inline void C(int x, int v)
{
	--cnt[a[x]][pos[x]];
	++cnt[v][pos[x]];
	a[x] = v;
	return ;
}

inline int Q(int l, int r, int v)
{
	int res = 0;
	if (pos[l] == pos[r])
	{
		for (int i = l; i <= r; i++) if (a[i] == v) ++res;
		return res;
	}
	for (int i = l; i <= pos[l]*block_num; i++) if (a[i] == v) ++res;
	for (int i = pos[l] + 1; i < pos[r]; i++) res += cnt[v][i];
	for (int i = (pos[r] - 1) * block_num + 1; i <= r; i++) if (a[i] == v) ++res;
	return res;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'C')
		{
			x = 0;
			return ;
		}
		if (ch == 'Q')
		{
			x = 1;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(T);
	block_num = (int)sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		b[++pt] = make_pair(a[i], &a[i]);
		pos[i] = (i - 1) / block_num + 1;
	}
	for (int i = 1; i <= T; i++)
	{
		read(opt);
		if (!opt)
		{
			read(c[i].a);
			read(c[i].p);
			c[i].opt = false;
			b[++pt] = make_pair(c[i].p, &c[i].p);
		}
		else
		{
			read(c[i].a);
			read(c[i].b);
			read(c[i].p);
			c[i].opt = true;
			b[++pt] = make_pair(c[i].p, &c[i].p);
		}
	}
	sort(b + 1, b + pt + 1);
	for (int i = 1; i <= pt; i++)
	{
		if (b[i].first != b[i - 1].first) ori[++m] = b[i].first;
		*b[i].second = m;
	}
	for (int i = 1; i <= n; i++) cnt[a[i]][pos[i]]++;
	for (int i = 1; i <= T; i++)
	{
		if (!c[i].opt) C(c[i].a, c[i].p);
		else printf("%d\n", Q(c[i].a, c[i].b, c[i].p));
	}
	return 0;
}