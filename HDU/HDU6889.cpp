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
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\n\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
ll n;
int pri[N], t1[N], t2[N], flag[N], pricnt, tot;
ll g[N], sum[N], a[N], T;
ll p;
inline int ID(ll x) { return (x <= T) ? t1[x] : t2[n / x]; }
inline ll jisuan(ll x) { return (x + 1) * x / 2 - 1; }
inline void init(ll n)
{
	pricnt = 0;
	T = sqrt(n + 0.5);
	mem(flag, 0, T, int);
	tot = 0;
	mem(t1, 0, T, int);
	mem(t2, 0, T, int);
	mem(g, 0, T, int);
	mem(sum, 0, T, int);
	for (int i = 2; i <= T; ++i)
	{
		if (!flag[i])
			pri[++pricnt] = i, sum[pricnt] = (i + sum[pricnt - 1]) % p;
		for (int j = 1; j <= pricnt && (ll)i * pri[j] <= T; ++j)
		{
			flag[i * pri[j]] = 1;
			if (i % pri[j] == 0)
				break;
		}
	}
	ll l = 1;
	while (l <= n)
	{
		a[++tot] = n / l;
		if (a[tot] <= T)
		{
			t1[a[tot]] = tot;
		}
		else
		{
			t2[n / a[tot]] = tot;
		}
		g[tot] = jisuan(a[tot]);
		l = n / (n / l) + 1;
	}
	for (int i = 1; i <= pricnt; ++i)
		for (int j = 1; (ll)pri[i] * pri[i] <= a[j] && j <= tot; ++j)
			g[j] -= pri[i] * (g[ID(a[j] / pri[i])] - sum[i - 1]), g[j] = (g[j] + p) % p;
}
inline ll calans(ll x)
{
	if (x <= 1)
		return x;
	return init(x), g[ID(x)];
}

inline void solve()
{
	scanf("%lld%lld", &n, &p);
	n++;
	ll tmp = calans(n);
	--n;
	ll ans = tmp;
	ans += (n + 1) % p * (n + 2) % p * (p + 1) / 2 % p;
	ans -= 5;
	ans = (ans + p) % p;
	printf("%lld\n", ans);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
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
