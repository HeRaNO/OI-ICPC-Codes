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
const double PI = acos(-1.0);
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
ll L, R, Q;

ll divisor(ll x)
{
	ll ret = 0;
	for (ll i = 1; i * i < x;++i)
	{
		if(x%i==0)
			ret += 2;
	}
	ll sq = sqrt(x);
	if(sq * sq == x)
		ret++;
	return ret;
}

void solve()
{
	cin >> L >> R >> Q;
	if (R < Q)
		return puts("infinity"), void();
	if (L / Q != R / Q)
	{
		printf("%lld\n", divisor(Q));
	}
	else
	{
		printf("%lld\n", divisor(Q * (L / Q)));
	}
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