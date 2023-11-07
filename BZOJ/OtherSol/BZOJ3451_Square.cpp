#include <cstdio>
#include <vector>
#include <atcoder/convolution>

using namespace atcoder;
using mint = modint998244353;

const int N = 30'005;

std::vector<int> g[N];
int n, G, SIZ;
int siz[N], mx[N], ans[N], max_dep[N];
bool vis[N];

void DFS_size_and_G(int x, int f)
{
	siz[x] = 1; mx[x] = 0;
	for (int v : g[x])
		if (v != f && !vis[v])
		{
			DFS_size_and_G(v, x);
			siz[x] += siz[v];
			mx[x] = std::max(mx[x], siz[v]);
		}
	mx[x] = std::max(mx[x], SIZ - siz[x]);
	if (mx[x] < mx[G]) G = x;
	return ;
}

void dfs_touch(int x, int f)
{
	max_dep[x] = 1;
	for (int v : g[x])
		if (v != f && !vis[v])
		{
			dfs_touch(v, x);
			max_dep[x] = std::max(max_dep[x], max_dep[v] + 1);
		}
	return ;
}

void dfs_leaf(int x, int f, int dep, std::vector<mint>& h)
{
	siz[x] = 1; ++h[dep];
	for (int v : g[x])
		if (v != f && !vis[v])
		{
			dfs_leaf(v, x, dep + 1, h);
			siz[x] += siz[v];
		}
	return ;
}

void work(int x, int y)
{
	std::vector<mint> f(max_dep[x] + 1);
	dfs_leaf(x, -1, y, f);
	auto r = convolution_square(f);
	int c = (y == 0) ? 1 : -1;
	for (int i = 0; i < r.size(); i++) ans[i] += r[i].val() * c;
	return ;
}

void TreeDC(int x)
{
	vis[x] = true;
	dfs_touch(x, 0); work(x, 0);
	for (int v : g[x])
		if (!vis[v])
			work(v, 1);
	for (int v : g[x])
		if (!vis[v])
		{
			SIZ = mx[0] = siz[v]; G = 0;
			DFS_size_and_G(v, x);
			TreeDC(G);
		}
	vis[x] = false;
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y; scanf("%d %d", &x, &y); ++x; ++y;
		g[x].push_back(y); g[y].push_back(x);
	}
	SIZ = mx[0] = n; G = 0;
	DFS_size_and_G(1, -1);
	TreeDC(G);
	double E = n;
	for (int i = 1; i < n; i++) E += (double)ans[i] / (i + 1);
	printf("%.4lf\n", E);
	return 0;
}
