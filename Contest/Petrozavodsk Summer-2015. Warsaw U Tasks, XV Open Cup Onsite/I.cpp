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
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 1050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
	#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
	#endif
}
int n, m, a, b;
pii lu;
char s[N][N], t[N][N];
int vis[N][N];
vector <pii> tx;

inline void solve()
{
	lu.first = lu.second = inf;
	memarray(vis, 0);
	scanf("%d%d%d%d", &n, &m, &a, &b);
	tx.resize(0);
	for (int i=1;i<=n;++i)
		scanf("%s", s[i]+1);
	for (int i=1;i<=a;++i)
		scanf("%s", t[i]+1);
	for (int i=1;i<=a;++i)
		for (int j=1;j<=b;++j)
			if (t[i][j]=='x')
				lu=min(lu, mp(i, j));
	int dx=lu.first, dy=lu.second;
	if (lu.first == inf)
	{
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				if (s[i][j]=='x')
					return puts("NIE"), void();
		return puts("TAK"), void();
	}
	for (int i=1;i<=a;++i)
		for (int j=1;j<=b;++j)
			if (t[i][j]=='x')
				tx.push_back(mp(i-dx+1, j-dy+1));
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
		{
			if (s[i][j] == 'x')
			{
				bool flag = true;
				for (auto k : tx)
				{
					int x = k.first, y=k.second;
					if (i+x-1 < 0 || j+y-1 < 0 || i+x-1 > n || j+y-1>m || s[i+x-1][j+y-1]=='.' || vis[i+x-1][j+y-1])
					{
						flag=0;
						break;
					}
				}
				if (flag)
				{
					for (auto k : tx)
					{
						int x=k.first, y=k.second;
						vis[i+x-1][j+y-1]++;
					}
				}
				if (!vis[i][j])
					return puts("NIE"), void();
			}
		}
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			if (vis[i][j]&&s[i][j]=='.')
				return puts("NIE"), void();
			if (!vis[i][j]&&s[i][j]=='x')
				return puts("NIE"), void();
		}
	puts("TAK");
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}