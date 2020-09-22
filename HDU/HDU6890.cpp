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
const int N = 1000050;
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
int n, m, k;
int a[N];
ll l, r;
ll sum;

inline void solve()
{
	l = llinf, r = -llinf;
	sum = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &a[i]), l = min(1ll * a[i], l), sum += abs(a[i] - k), r = max(r, 1ll * a[i]);
	if (l > k)
	{
		printf("%lld", 2 * (sum + k - 1));
		return;
	}
	ll ans1 = (l - 1) * 2;
	sum *= 2;
	// sum -= abs(l - k);
	printf("%lld", ans1 + sum);
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
		putchar('\n');
	}
	TIME__END = clock();
	program_end();
	return 0;
}
