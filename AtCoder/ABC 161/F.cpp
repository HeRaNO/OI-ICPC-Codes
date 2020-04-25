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
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
ll n;
set<ll> s;
inline ll mi(ll a, ll b)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1)
			ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}

void check(ll d)
{
	for (ll i = 1; i <= 60; ++i)
	{
		ll k = pow(d * 1.0, 1.0 / i);
		if (k == 1)
			continue;
		if (mi(k, i) == d)
		{
			if ((n / d - 1 + k) % k == 0)
				s.insert(k);
		}
		if (mi(k + 1, i) == d)
		{
			if ((n / d - 1 + k + 1) % (k + 1) == 0)
				s.insert(k + 1);
		}
		if (k > 1 && mi(k - 1, i) == d)
		{
			if ((n / d - 1 + k - 1) % (k - 1) == 0)
				s.insert(k - 1);
		}
	}
}

void solve()
{
	cin >> n;
	for (ll i = 1; i * i <= n - 1; ++i)
	{
		if ((n - 1) % i == 0)
		{
			s.insert(i);
			s.insert((n - 1) / i);
		}
	}
	for (ll i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			check(i);
			check(n / i);
		}
	}
	check(n);
	s.erase(1);
	cout << s.size() << '\n';
	// for (auto i : s)
	//     cout << i << ' ';
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