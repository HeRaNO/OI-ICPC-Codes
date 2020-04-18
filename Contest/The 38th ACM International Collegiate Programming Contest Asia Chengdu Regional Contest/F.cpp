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

int kase;
int n, m;
int f[N];
int Find(int x) { return x == f[x] ? x : f[x] = Find(f[x]); }
struct edge
{
	int x, y, w;
	bool operator<(const edge &x) const
	{
		return w < x.w;
	}
} e[N];
int fib[N];
bool yes[N];

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
	sort(e + 1, e + m + 1);
	int sum1 = 0, sum2 = 0;
	int tot = 0;
	for (int i = 1; i <= m; ++i)
	{
		int fx = Find(e[i].x), fy = Find(e[i].y);
		if (fx != fy)
		{
			f[fy] = fx;
			tot++;
			sum1 += e[i].w;
			if (tot == n - 1)
				break;
		}
	}
	if (tot != n - 1)
	{
		puts("No");
		return;
	}
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	tot = 0;
	for (int i = m; i >= 1; --i)
	{
		int fx = Find(e[i].x), fy = Find(e[i].y);
		if (fx != fy)
		{
			f[fy] = fx;
			tot++;
			sum2 += e[i].w;
			if (tot == n - 1)
				break;
		}
	}
	for (int i = sum1; i <= sum2; ++i)
	{
		if (yes[i])
		{
			puts("Yes");
			return;
		}
	}
	puts("No");
}

int main()
{
	TIME_START = clock();
	fib[1] = 1, fib[2] = 1;
	yes[1] = true;
	for (int i = 3; fib[i - 1] <= 100000; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] <= 100000)
		{
			yes[fib[i]] = true;
		}
	}
	int Test = 1;
	cin >> Test;
	while (Test--)
		printf("Case #%d: ", ++kase), solve();
	TIME_END = clock();
	program_end();
	return 0;
}