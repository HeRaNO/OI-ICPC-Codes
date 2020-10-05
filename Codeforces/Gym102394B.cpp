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
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e8 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\n\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int m, n;
int L[N], R[N];
ll dp[N];
const int SIZ = 100000000 + 3;
char buf1[SIZ];
char *p1 = buf1, *p2 = buf1;
inline char readchar()
{
	if (p1 == p2)
		p1 = buf1, p2 = buf1 + fread(buf1, 1, SIZ, stdin);
	return p1 == p2 ? EOF : *p1++;
}
inline int read()
{
	int ret, c;
	while ((c = readchar()) > '9' | c < '0')
		;
	ret = c - '0';
	while ((c = readchar()) >= '0' && c <= '9')
		ret = ret * 10 + c - '0';
	return ret;
}
inline void Add(ll &x, ll y)
{
	x += y;
	if (x > MOD)
		x -= MOD;
}
inline void Sub(ll &x, ll y)
{
	x -= y;
	if (x < 0)
		x += MOD;
}
inline int f(int a, int b)
{
	int ret = 0;
	int i = m - 1;
	while (((a & st(i)) == (b & st(i))) && i >= 0)
		i--, ret++;
	return ret;
}

inline void solve()
{
	m = read(), n = read();
	// cin >> m >> n;
	for (int i = 1; i <= n; ++i)
		L[i] = read(), R[i] = read();
		// cin >> L[i] >> R[i];
	mem(dp, 0, st(m), ll);
	for (int j = 0; j <= R[1]; ++j)
		dp[j] = j;
	for (int i = 2; i <= n; ++i)
	{
		ll sum = 0;
		int l, r;
		l = r = L[i - 1];
		for (int j = R[i]; j >= L[i]; --j)
		{
			while (r <= R[i - 1] && f(r, L[i]) <= f(j, L[i]))
			{
				Add(sum, dp[r]);
				r++;
			}
			while (l <= r && f(l, R[i - 1]) < f(j, R[i - 1]))
			{
				Sub(sum, dp[l]);
				l++;
			}
			dp[j] = sum * j % MOD;
		}
	}
	ll ans = 0;
	for (int j = L[n]; j <= R[n]; ++j)
		Add(ans, dp[j]);
	printf("%lld\n", ans);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	Test = read();
	while (Test--)
	{
		solve();
		// if (Test)
		//     putchar('\n');
	}
	TIME__END = clock();
	program_end();
	return 0;
}