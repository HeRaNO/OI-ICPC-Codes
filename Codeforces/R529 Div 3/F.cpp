#include <cstdio>
#include <iostream>
#include <algorithm>
#define mp make_pair
#define fi first
#define se second
using namespace std;

int n, m, mn, u, v, cnt, pt, f[200010], fx, fy;
long long w, sum, a[200010];

pair <long long, pair<int, int> > p[300010];

inline int getf(int x)
{
	return x == f[x] ? x : f[x] = getf(f[x]);
}

int main()
{
	a[mn] = ~(1LL << 63);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++)
	{
		scanf("%I64d", &a[i]);
		if (a[mn] > a[i]) mn = i;
	}
	for (int i = 1; i <= n; i++)
		if (i != mn) p[++pt] = mp(a[i] + a[mn], mp(i, mn));
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %I64d", &u, &v, &w);
		p[++pt] = mp(w, mp(u, v));
	}
	sort(p + 1, p + pt + 1);
	for (int i = 1; i <= pt; i++)
	{
		fx = getf(p[i].se.fi);
		fy = getf(p[i].se.se);
		if (fx != fy)
		{
			f[fy] = fx;
			sum += p[i].fi;
			++cnt;
			if (cnt == n - 1) break;
		}
	}
	printf("%I64d\n", sum);
	return 0;
}