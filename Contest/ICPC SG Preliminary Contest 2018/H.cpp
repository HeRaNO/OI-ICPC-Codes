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
int R, K, n;
int a[N][10];
int vis[N], yes[N];
int num[N];
int f[N];
int Find(int x) { return x == f[x] ? x : f[x] = Find(f[x]); }
void uni(int x, int y)
{
	int fx = Find(x), fy = Find(y);
	if (fx != fy)
		f[fy] = fx;
}

inline void solve()
{
	scanf("%d%d", &R, &K);
	for (int i = 1; i <= K; ++i)
		scanf("%d", &num[i]), yes[num[i]] = 1;
	int m = R * R * R - (R - 1) * (R - 1) * (R - 1);
	for (int i = 1; i <= m + 5; ++i)
		f[i] = i;
	int ans = 0;
	int now = 0;
	int up = 0;
	for (int i = 1; i <= 2 * R - 1; ++i)
	{
		for (int j = 1; j <= R + up; ++j)
		{
			++now;
			if (j < R + up)
			{
				a[now][1] = now + 1;
				a[now + 1][4] = now;
				if (!yes[now] && !yes[now + 1])
					uni(now, now + 1);
			}
			if (((i >= R && j < R + up) || i < R) && (i < 2 * R - 1))
			{
				a[now][6] = now + (R + up + (i < R));
				a[now + (R + up + (i < R))][3] = now;
				if (!yes[now] && !yes[now + (R + up + (i < R))])
					uni(now, now + (R + up + (i < R)));
			}
			if (((i < R) || (i >= R && j > 1)) && i < 2 * R - 1)
			{
				a[now][5] = now + (R + up - 1 + (i < R));
				a[now + (R + up - 1 + (i < R))][2] = now;
				if (!yes[now] && !yes[now + (R + up - 1 + (i < R))])
					uni(now, now + (R + up - 1 + (i < R)));
			}
			if (j == 1 || j == R + up || i == 1 || i == 2 * R - 1)
			{
				if (!yes[now])
					uni(now, m + 1);
			}
		}
		if (i < R)
			up++;
		else
			up--;
	}
	for (int i = 1; i <= m; ++i)
	{
		if (yes[i])
			continue;
		if (Find(i) != Find(m + 1))
			num[++K] = i;
	}
	for (int i = 1; i <= K; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= 6; ++j)
			sum += vis[a[num[i]][j]];
		vis[num[i]] = 1;
		ans += 6 - 2 * sum;
	}
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