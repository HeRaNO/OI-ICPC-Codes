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
const int N = 100050;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n, m;
int f[N];
int c[N];
int Find(int x)
{
	if (x == f[x])
		return x;
	int F = Find(f[x]);
	c[x] ^= c[f[x]];
	return f[x] = F;
}
inline ll mi(ll a, ll b)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1)
			ret *= a, ret %= mod;
		a *= a, a %= mod;
		b >>= 1;
	}
	return ret;
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		int fx = Find(x), fy = Find(y);
		w ^= 1;
		if (fx == fy)
		{
			if ((w && c[x] == c[y]) || (!w && c[x] != c[y]))
				return puts("0"), void();
		}
		else
		{
			f[fy] = fx;
			c[fy] = c[x] ^ c[y] ^ w;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (Find(i) == i)
			cnt++;
	cout << mi(2, cnt - 1) << endl;
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