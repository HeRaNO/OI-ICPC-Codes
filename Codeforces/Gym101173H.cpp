#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define lowbit(x) x & -x
#define pb push_back
#define ls (u << 1)
#define rs (u << 1 | 1)
#define ALL(x) (x).begin(), (x).end()
#define UNI(x) sort(ALL(x)), x.resize(unique(ALL(x)) - x.begin())
#define GETPOS(c, x) (lower_bound(ALL(c), x) - c.begin())
#define LEN(x) strlen(x)
#define MS0(x) memset((x), 0, sizeof((x)))
#define Rint register int
typedef unsigned int unit;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<pii> Vpii;
template <class T>
void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(ll &x) { scanf("%lld", &x); }
void _R(ull &x) { scanf("%llu", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &... tail)
{
	_R(head);
	R(tail...);
}
template <class T>
void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x)
{
	_W(x.fi);
	putchar(' ');
	_W(x.se);
}
template <class T>
void _W(const vector<T> &x)
{
	for (auto i = x.begin(); i != x.end(); _W(*i++))
		if (i != x.cbegin())
			putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &... tail)
{
	_W(head);
	putchar(sizeof...(tail) ? ' ' : '\n');
	W(tail...);
}
const int MOD = 1e9 + 7, mod = 998244353;
ll qpow(ll a, ll b)
{
	ll res = 1;
	a %= MOD;
	assert(b >= 0);
	for (; b; b >>= 1)
	{
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
	}
	return res;
}
const int MAXN = 4e6 + 10, MAXM = 2e6 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const ll llINF = LLONG_MAX;
const int inv2 = (MOD + 1) / 2;
const int Lim = 1 << 20;

struct Node
{
	int x, y, sx, sy, dis;
	bool operator<(const Node &rhs) const
	{
		return dis > rhs.dis;
	}
};

int n, m, q;
char s[1005][1005];
int getid(int i, int j)
{
	return i * (n + 2) + j;
}
bool valid(int i, int j)
{
	return i >= 0 && j >= 0 && i <= n + 1 && j <= n + 1;
}
struct Query
{
	int sx, sy, tx, ty;
} Q[MAXN];

priority_queue<Node> pq;
int dis[1105][1105];
int D[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
Vpii vec[MAXN];
int sum[1105][1105];

int fa[MAXN];
int _find(int x)
{
	return fa[x] ^ x ? fa[x] = _find(fa[x]) : fa[x];
}

void _union(int u, int v)
{
	u = _find(u);
	v = _find(v);
	if (u == v)
		return;
	fa[u] = v;
}

bool ok[1105][1105];

void addnode(int x, int y)
{
	ok[x][y] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int tx = x + D[i][0], ty = y + D[i][1];
		if (!valid(tx, ty))
			continue;
		if (s[tx][ty] == '#')
			continue;
		if (!ok[tx][ty])
			continue;
		_union(getid(x, y), getid(tx, ty));
	}
}
bool check(int x, int y, int mid)
{
	if (x - mid - 1 < 0 || y - mid - 1 < 0 || x + mid > n + 1 || y + mid > n + 1)
		return 0;
	return sum[x + mid][y + mid] - sum[x - mid - 1][y + mid] - sum[x + mid][y - mid - 1] + sum[x - mid - 1][y - mid - 1] == 0;
}

int ans[MAXN];
void solve()
{
	R(n);
	m = n;
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	R(q);
	for (int i = 0; i <= (n + 2) * (n + 2) + 5; i++)
		fa[i] = i;
	for (int i = 0; i <= n + 1; i++)
		s[i][0] = s[i][n + 1] = '#';
	for (int i = 0; i <= n + 1; i++)
		s[0][i] = s[n + 1][i] = '#';
	for (int i = 1; i <= q; i++)
	{
		R(Q[i].sx, Q[i].sy, Q[i].tx, Q[i].ty);
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			if (s[i][j] == '#')
			{
				// pq.push({i,j,i,j,dis[i][j]=0});
				sum[i][j] = 1;
			}
	for (int i = 1; i <= n + 1; ++i)
	{
		for (int j = 1; j <= n + 1; ++j)
		{
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s[i][j] == '.')
			{
				int l = 0, r = n;
				while (l <= r)
				{
					int mid = (l + r) >> 1;
					if (check(i, j, mid))
						l = mid + 1, dis[i][j] = mid;
					else
						r = mid - 1;
				}
				// printf("%d %d %d\n", i, j, dis[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '.' && dis[i][j] <= n)
				vec[dis[i][j]].pb({i, j});
	for (int i = n / 2 + 1; ~i; i--)
	{
		for (auto j : vec[i])
		{
			addnode(j.fi, j.se);
		}
		for (int j = 1; j <= q; j++)
		{
			if (_find(getid(Q[j].sx, Q[j].sy)) == _find(getid(Q[j].tx, Q[j].ty)))
				ans[j] = max(ans[j], i * 2 + 1);
		}
	}
	for (int i = 1; i <= q; i++)
		W(ans[i]);
}

int main()
{
	int T = 1;
	//R(T);
	while (T--)
		solve();
	//system("pause");
	return 0;
}
