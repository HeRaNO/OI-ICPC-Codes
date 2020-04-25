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
const int N = 4050;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
ll S[N][N];
ll C[N][N];
ll sum[N];
int n;

void Init_C()
{
	C[0][0] = 1;
	for (int i = 1; i <= 4000; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
}
void Init_S()
{
	S[0][0] = 1;
	sum[0] = 1;
	for (int i = 1; i <= 4000; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			S[i][j] = (S[i - 1][j] * j + S[i - 1][j - 1]) % mod;
			sum[i] += S[i][j];
			sum[i] %= mod;
		}
	}
}

void solve()
{
	Init_C();
	Init_S();
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += (C[n][i] * sum[i]) % mod;
		ans %= mod;
	}
	cout << ans << '\n';
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