#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 50010
#define MAXB 230
using namespace std;

long long c[MAXB], a[MAXN], x, d[MAXB], b[MAXN];
int n, m, opt, l, r, pos[MAXN];

inline void clean(int x)
{
	int l = (x - 1) * m + 1, r = min(x * m, n);
	for (int i = l; i <= r; i++) b[i] = a[i];
	sort(b + l, b + r + 1);
	return ;
}

inline void modify(int l, int r, long long x)
{
	if (pos[l] == pos[r])
	{
		for (int i = l; i <= r; i++) a[i] += x;
		clean(pos[l]);
		return ;
	}
	for (int i = l; i <= min(pos[l]*m, n); i++) a[i] += x;
	for (int i = pos[l] + 1; i < pos[r]; i++) d[i] += x;
	for (int i = (pos[r] - 1) * m + 1; i <= r; i++) a[i] += x;
	clean(pos[l]);
	clean(pos[r]);
	return ;
}

inline int query(int l, int r, long long x)
{
	int ans = 0, pt;
	long long p;
	if (pos[l] == pos[r])
	{
		p = d[pos[l]];
		for (int i = l; i <= r; i++) ans += (a[i] + p < x);
		return ans;
	}
	for (int i = l, p = d[pos[l]]; i <= min(pos[l]*m, n); i++) ans += (a[i] + p < x);
	for (int i = pos[l] + 1, p; i < pos[r]; i++)
	{
		int pl = (i - 1) * m + 1, pr = i * m;
		pt = lower_bound(b + pl, b + pr + 1, x - d[i]) - b;
		pt -= pl;
		ans += pt;
	}
	for (int i = (pos[r] - 1) * m + 1, p = d[pos[r]]; i <= r; i++) ans += (a[i] + p < x);
	return ans;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

inline void read(long long &x)
{
	x = 0LL;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3LL) + (x << 1LL) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	m = (int)sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		b[i] = a[i];
		pos[i] = (i - 1) / m + 1;
	}
	for (int i = 1; i <= pos[n]; i++) clean(i);
	for (int i = 1; i <= n; i++)
	{
		read(opt);
		read(l);
		read(r);
		read(x);
		if (!opt) modify(l, r, x);
		else printf("%d\n", query(l, r, x * x));
	}
	return 0;
}