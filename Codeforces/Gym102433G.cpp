#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
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
int n;
pii v[N], h[N];
int nv, nh;
int h1[N], h2[N];
ll ans;

int check1(int x)
{
	int L = 1, R = nh, ret = nh + 1;
	while (L <= R)
	{
		int mid = (L + R) >> 1;
		if (h2[mid] >= x)
			ret = mid, R = mid - 1;
		else
			L = mid + 1;
	}
	return ret;
}
int check2(int x)
{
	int L = 1, R = nh, ret = nh + 1;
	while (L <= R)
	{
		int mid = (L + R) >> 1;
		if (h1[mid] > x)
			ret = mid, R = mid - 1;
		else
			L = mid + 1;
	}
	return ret;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		char op[2];
		int t, m, d;
		scanf("%s", op);
		scanf("%d%d%d", &t, &m, &d);
		if (op[0] == 'v')
			v[++nv] = make_pair(t - d, t - d + m - 1);
		else
		{
			h[++nh] = make_pair(t - d, t - d + m - 1);
			h1[nh] = t - d;
			h2[nh] = t - d + m - 1;
		}
	}
	sort(h + 1, h + nh + 1);
	sort(h1 + 1, h1 + nh + 1);
	sort(h2 + 1, h2 + nh + 1);
	sort(v + 1, v + nv + 1);
	for (int i = 1; i <= nv; ++i)
	{
		int l = check1(v[i].first), r = check2(v[i].second);
		ans += r - l;
	}
	printf("%lld\n", ans);
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