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
int n;
int a[N], c[N];

inline void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	if (n == 1)
	{
		if (a[1] > 1)
			puts("0");
		else
			puts("1");
		return;
	}
	ll g2 = a[1];
	for (int i = 2; i <= n; ++i)
		g2 = __gcd(g2, (long long)a[i]);
	if (g2 > 1)
		return puts("0"), void();
	int g = a[2] - a[1];
	for (int i = 2; i < n; ++i)
	{
		int num = a[i + 1] - a[i];
		g = __gcd(g, num);
	}
	if (g == 1)
		return puts("-1"), void();
	for (ll i = 2; i * i <= g; ++i)
		if (g % i == 0)
		{
			g = i;
			break;
		}
	int ans = a[1] % g;
	ans = g - ans;
	printf("%d\n", ans);
}

int main()
{
	TIME__START = clock();
	int Test = 1, kase = 0;
	scanf("%d", &Test);
	while (Test--)
	{
		printf("Case %d: ", ++kase);
		solve();
		// if (Test)
		//     putchar('\n');
	}
	TIME__END = clock();
	program_end();
	return 0;
}