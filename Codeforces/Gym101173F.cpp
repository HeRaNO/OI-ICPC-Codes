#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n;
int f[N];
int Find(int x) { return x == f[x] ? x : f[x] = Find(f[x]); }
int e[N], g[N];
int ine[N], outg[N];
int fae[N], fag[N];
int ans;
int du[N];
set<int> s;
void del(int u)
{
	while (u > 0)
	{
		int nxt = fae[u];
		fae[u] = -1;
		if (nxt > 0)
			du[nxt]--, du[u]--;
		if (nxt > 0)
			s.insert(nxt), ans++;
		u = nxt;
	}
}
void Union(int x, int y)
{
	int fx = Find(x), fy = Find(y);
	if (fx != fy)
		f[fy] = fx;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	for (int i = 1; i <= n; ++i)
	{
		int father;
		scanf("%d", &father);
		if (father == 0)
			continue;
		e[father] = i;
		fae[i] = father;
		du[i]++, du[father]++;
		Union(i, father);
	}
	for (int i = 1; i <= n; ++i)
	{
		int father;
		scanf("%d", &father);
		// if (father == 0)
		//     continue;
		if (father)
		{
			g[father] = i;
			fag[i] = father;
			outg[father]++;
			if (Find(i) != Find(father))
			{
				del(i);
				del(father);
			}
		}
		if (fae[i] != fag[i])
		{
			del(i);
		}
	}
	for (int i = 1; i <= n; ++i)
		if (du[i] == 0)
			s.insert(i);
	ans += s.size();
	for (auto u : s)
	{
		if (outg[u] == 0)
			ans--;
	}
	printf("%d\n", ans);
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}
