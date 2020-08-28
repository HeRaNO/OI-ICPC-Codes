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
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int a[5][5];
int c[10];
int ans;

inline void solve()
{
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j)
			scanf("%d", &a[i][j]);
	ans = 0;
	for (int i1 = 1; i1 <= 3; ++i1)
		for (int j1 = 1; j1 <= 3; ++j1)
		{
			bool flag = true;
			for (int i2 = 1; i2 <= 3; ++i2)
				for (int j2 = 1; j2 <= 3; ++j2)
				{
					if (i2 == i1 || j1 == j2)
						continue;
					int xorsum = 0;
					for (int i3 = 1; i3 <= 3; ++i3)
						for (int j3 = 1; j3 <= 3; ++j3)
						{
							if ((i3 == i1 && j3 == j1) || (i3 == i2 && j3 == j2))
								continue;
							if ((6 - i1 - i2) == i3 && (6 - j1 - j2) == j3)
								xorsum ^= a[i3][j3];
							else
								xorsum ^= a[i3][j3] - 1;
						}
					if(xorsum == 0)
						flag = false;
				}
			ans += flag;
		}
	printf("%d\n", ans);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}