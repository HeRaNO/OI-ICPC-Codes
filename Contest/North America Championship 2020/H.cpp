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
char s[5][5050];
int n;
const int base1 = 131, base2 = 233;
int ans = inf;
map<pair<ll, ll>, int> h;
ll b1[5050], b2[5050];
void work()
{
	h.clear();
	for (int i = 0; i < n; ++i)
	{
		ll hash1 = 0, hash2 = 0;
		for (int j = i; j < i + n; ++j)
		{
			hash1 += s[3][j % n] * b1[j - i] % mod;
			hash1 %= mod;
			hash2 += s[3][j % n] * b2[j - i] % MOD;
			hash2 %= MOD;
		}
		if (!h.count(mp(hash1, hash2)))
			h.insert(mp(mp(hash1, hash2), min(i, n - i)));
		else
			h[mp(hash1, hash2)] = min(h[mp(hash1, hash2)], min(i, n - i));
	}
	for (int i = 0; i < n; ++i)
	{
		ll hash1 = 0, hash2 = 0;
		bool flag = true;
		for (int j = i; j < i + n; ++j)
		{
			if (s[1][(j - i) % n] == s[2][j % n])
				flag = 0;
		}
		if (!flag)
			continue;
		for (int j = i; j < i + n; ++j)
		{
			int c = 65 + 66 + 67 - s[1][(j - i) % n] - s[2][j % n];
			hash1 += c * b1[j - i] % mod;
			hash1 %= mod;
			hash2 += c * b2[j - i] % MOD;
			hash2 %= MOD;
		}
		if (!h.count(mp(hash1, hash2)))
			continue;
		int b = i, c = h[mp(hash1, hash2)];
		int now = min(c, n - c) + min(b, n - b);
		ans = min(ans, now);
	}
}

inline void solve()
{
	for (int i = 1; i <= 3; ++i)
		scanf("%s", s[i]);
	n = strlen(s[1]);
	b1[0] = 1, b2[0] = 1;
	for (int i = 1; i <= 5005; ++i)
		b1[i] = b1[i - 1] * base1 % mod, b2[i] = b2[i - 1] * base2 % MOD;
	work();
	swap(s[1], s[2]);
	work();
	swap(s[1], s[2]);
	swap(s[1], s[3]);
	work();
	swap(s[1], s[3]);
	swap(s[2], s[3]);
	work();
	swap(s[2], s[3]);
	if (ans == inf)
		ans = -1;
	printf("%d\n", ans);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
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