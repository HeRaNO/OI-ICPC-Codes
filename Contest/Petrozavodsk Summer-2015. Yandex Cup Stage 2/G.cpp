#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define fillarray(array, value, begin, end) fill((array) + (begin), (array) + (end) + 1, value)
#define fillvector(v, value) fill((v).begin(), (v).end(), value)
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
const int N = 250;
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
int n, q, L;
int f[N];
int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]); }
char s[N][N];
char b[N];
vector<pair<char, int>> p[N];

inline void solve()
{
	scanf("%d%d", &n, &L);
	for (int i = 1; i <= n; ++i)
	{
		p[i].resize(0);
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= L; ++j)
			p[i].push_back(mp(s[i][j], j));
	}
	for (int i = 1; i <= n; ++i)
		vecupsort(p[i]);
	scanf("%d", &q);
	while (q--)
	{
		scanf("%s", b + 1);
		for (int i = 1; i <= L; ++i)
			f[i] = i;
		for (int i = 1; i <= n; ++i)
		{
			if (b[i] == '1')
			{
				for (int j = 1; j < (int)p[i].size(); ++j)
				{
					if (p[i][j].first == p[i][j - 1].first)
					{
						int fx = Find(p[i][j - 1].second), fy = Find(p[i][j].second);
						if (fx != fy)
							f[fy] = fx;
					}
				}
			}
		}
		bool vis[N] = {0};
		int m = 0;
		for (int i = 1;i<=L;++i)
		{
			if(!vis[Find(i)])
				vis[Find(i)] = 1, ++m;
		}
		cout << "1*2^" << 4 * m << '\n';
	}
}

int main()
{
	freopen("git-hashes.in", "r", stdin);
	freopen("git-hashes.out", "w", stdout);
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}