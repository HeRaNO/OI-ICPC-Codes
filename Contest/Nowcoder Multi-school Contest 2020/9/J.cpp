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
const int N = 550;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n, m;
int a[N][N], b[N][N];
int sx[N][N], sy[N][N], sb[N][N];
ll ans;
int cnt[500050];
const int C = 250001;
inline int matsum(int x1, int y1, int x2, int y2)
{
	if (x1 > x2 || y1 > y2)
		return 0;
	return sb[x2][y2] - sb[x1 - 1][y2] - sb[x2][y1 - 1] + sb[x1 - 1][y1 - 1];
}

inline void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &a[i][j]);
			sx[i][j] = sx[i][j - 1] + a[i][j];
			sy[i][j] = sy[i - 1][j] + a[i][j];
			b[i][j] = (a[i][j] ? 1 : -1);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			sb[i][j] = sb[i - 1][j] + sb[i][j - 1] - sb[i - 1][j - 1] + b[i][j];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			vector<int> lieno;
			for (int k = 1; k <= m; ++k)
				if (sy[j][k] - sy[i - 1][k] == j - i + 1)
					lieno.push_back(k);
			if (lieno.size() <= 1)
				continue;
			int l = 0;
			cnt[C] = 1;
			vector<int> have;
			have.push_back(C + i - j + 1);
			for (int k = 1; k < (int)lieno.size(); ++k)
			{
				if (sx[i][lieno[k]] - sx[i][lieno[k - 1] - 1] != lieno[k] - lieno[k - 1] + 1 || sx[j][lieno[k]] - sx[j][lieno[k - 1] - 1] != lieno[k] - lieno[k - 1] + 1)
				{
					for (int t = l + 1; t < k; ++t)
					{
						cnt[matsum(i + 1, lieno[l] + 1, j - 1, lieno[t]) + C] = 0;
						//have.push_back(matsum(i + 1, lieno[t] + 1, j - 1, lieno[t]) + C);
					}
					cnt[C] = 1;
					l = k;
					continue;
				}
				int nowsum = matsum(i + 1, lieno[l] + 1, j - 1, lieno[k]);
				for (int t = nowsum + i - j; t <= nowsum + i - j + 2; ++t)
					ans += cnt[t + C];
				cnt[nowsum + C]++;
				have.push_back(nowsum + C);
			}
			for (auto k : have)
				cnt[k] = 0;
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	//  freopen("J.in","r",stdin);
	//  freopen("J.out","w",stdout);
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}
