#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
using namespace std;

typedef pair<int, int> pi;

int R, C, n, m, x, y, c[MAXN];
long long ans;
set <pi> a[MAXN], b[MAXN];
vector <pair<int, pi> > f1, g1, f2, g2;

int lowbit(int x)
{
	return x & (-x);
}
int query(int x)
{
	int res = 0;
	for (; x; x -= lowbit(x)) res += c[x];
	return res;
}
void add(int x, int v)
{
	for (; x <= C; x += lowbit(x)) c[x] += v;
	return ;
}

bool get_track(int x, int y, int d, vector <pair<int, pi> > &f, vector <pair<int, pi> > &g)
{
	f.clear();
	g.clear();
	set <pi> :: iterator it;
	while (true)
	{
		if (d & 1)
		{
			if (d == 1)
			{
				it = b[y].upper_bound(make_pair(x, 1));
				f.push_back(make_pair(x + 1, make_pair(y, 1)));
				if (it == b[y].end())
				{
					f.push_back(make_pair(R + 1, make_pair(y, -1)));
					return false;
				}
				f.push_back(make_pair(it->first, make_pair(y, -1)));
				x = it->first;
				d = it->second ? 2 : 0;
			}
			else
			{
				it = b[y].lower_bound(make_pair(x, 0));
				f.push_back(make_pair(x, make_pair(y, -1)));
				if (it == b[y].begin())
				{
					f.push_back(make_pair(1, make_pair(y, 1)));
					return false;
				}
				it--;
				f.push_back(make_pair(it->first + 1, make_pair(y, 1)));
				x = it->first;
				d = it->second ? 0 : 2;
			}
		}
		else
		{
			if (!d)
			{
				it = a[x].upper_bound(make_pair(y, 1));
				if (it == a[x].end())
				{
					g.push_back(make_pair(x, make_pair(y + 1, C)));
					return x == R;
				}
				g.push_back(make_pair(x, make_pair(y + 1, it->first - 1)));
				y = it->first;
				d = it->second ? 3 : 1;
			}
			else
			{
				it = a[x].lower_bound(make_pair(y, 0));
				if (it == a[x].begin())
				{
					g.push_back(make_pair(x, make_pair(1, y - 1)));
					return false;
				}
				it--;
				g.push_back(make_pair(x, make_pair(it->first + 1, y - 1)));
				y = it->first;
				d = it->second ? 1 : 3;
			}
		}
	}
}

void get_ans(vector <pair<int, pi> > &f, vector <pair<int, pi> > &g)
{
	sort(f.begin(), f.end());
	sort(g.begin(), g.end());
	int m = f.size(), n = g.size(), j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j < m && f[j].first <= g[i].first) add(f[j].second.first, f[j].second.second), j++;
		int ll = g[i].second.first, rr = g[i].second.second;
		int res = query(rr) - query(ll - 1);
		ans += res;
		if (g[i].first < x && res)
		{
			x = g[i].first;
			y = ll;
			for (int j = 20; ~j; j--)
				if (y + (1 << j) <= rr && !(query(y - 1 + (1 << j)) - query(y - 1))) y += 1 << j;
		}
	}
	while (j < m) add(f[j].second.first, f[j].second.second), j++;
	return ;
}

int main()
{
	while (~scanf("%d %d %d %d", &R, &C, &n, &m))
	{
		memset(c, 0, sizeof c);
		for (int i = 0; i <= R; i++) a[i].clear();
		for (int i = 0; i <= C; i++) b[i].clear();
		for (int i = 1; i <= n + m; i++)
		{
			scanf("%d %d", &x, &y);
			a[x].insert(make_pair(y, i <= n));
			b[y].insert(make_pair(x, i <= n));
		}
		if (get_track(1, 0, 0, f1, g1))
		{
			puts("0");
			continue;
		}
		get_track(R, C + 1, 2, f2, g2);
		ans = 0LL;
		x = R + 1;
		get_ans(f1, g2);
		get_ans(f2, g1);
		if (ans) printf("%lld %d %d\n", ans, x, y);
		else puts("-1");
	}
	return 0;
}
