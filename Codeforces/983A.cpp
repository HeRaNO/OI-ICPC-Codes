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
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
ll p, q, b;
inline ll gcd(ll A, ll B) { return B == 0 ? A : gcd(B, A % B); }
ll pri[N];
int tot;
ll vis[N];
void pregao()
{
	for (int i = 2; i <= 100; ++i)
	{
		if (!vis[i])
			vis[i] = i, pri[++tot] = i;
		for (int j = 1; j <= tot && i * pri[j] <= 100; ++j)
		{
			vis[i * pri[j]] = i;
			if (i % pri[j] == 0)
				break;
		}
	}
}
vector<ll> pp;

void solve()
{
	scanf("%lld%lld%lld", &p, &q, &b);
	ll g = gcd(p, q);
	p /= g, q /= g;
	// if (b <= 1e6)
	// {
	//     ll num = b;
	//     while (num)
	//     {
	//         ll prime = vis[num];
	//         while (num % prime == 0)
	//             num /= prime;
	//         pp.push_back(prime);
	//     }

	// }
	// else
	// {
	for (int i = 1; i <= tot; ++i)
	{
		if (b % pri[i] == 0)
		{
			while (q % pri[i] == 0)
				q /= pri[i];
		}
	}
	while (q != 1)
	{
		g = gcd(b, q);
		if (g == 1)
			break;
		q /= g;
	}
	if (q != 1)
		puts("Infinite");
	else
		puts("Finite");
	//     }
}

int main()
{
	// freopen("A.in", "r", stdin);
	// freopen("A.out", "w", stdout);
	TIME_START = clock();
	pregao();
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}