#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 200005
using namespace std;

vector<int> s[MAXN], g[MAXN];
int n, m, R, ans[MAXN][3];
int c[MAXN], d[MAXN], in[MAXN], out[MAXN], siz[MAXN];
pair<int, int> a[MAXN];

int lowbit(int x){ return x & -x; }
void add(int c[], int x, int v){ for (; x <= n; x += lowbit(x)) c[x] += v; return ; }
int query(int c[], int x){ int r = 0; for (; x; x -= lowbit(x)) r += c[x]; return r ; }

void dfs(int x)
{
	in[x] = ++R; siz[x] = 1;
	for (int v : g[x])
		dfs(v), siz[x] += siz[v];
	out[x] = R;
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 2, f; i <= n; i++)
		scanf("%d", &f), g[f].push_back(i);
	for (int i = 1, x; i <= n; i++)
		scanf("%d", &x), a[i] = {x, i};
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (i == 1 || a[i].first != a[i - 1].first) ++m;
		s[m].push_back(a[i].second);
	}
	dfs(1);
	for (int i = 1; i <= m; i++)
	{
		for (int j : s[i])
			add(d, in[j], 1);
		for (int x : s[i])
		{
			for (int r : g[x])
			{
				int lt = query(c, out[r]) - query(c, in[r] - 1);
				int ge = siz[r] - lt;
				ans[x][0] += lt;
				ans[x][1] += query(d, out[r]) - query(d, in[r] - 1);
				ans[x][2] += ge;
			}
			ans[x][2] -= ans[x][1];
		}
		for (int j : s[i])
			add(d, in[j], -1), add(c, in[j], 1);
	}
	for (int i = 1; i <= n; i++)
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
	return 0;
}