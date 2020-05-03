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
int n;
struct point
{
	int x, y;
	bool operator<(const point &X) const
	{
		return x < X.x;
	}
} a[10], b[10];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;
	for (int i = 1; i <= n; ++i)
		cin >> b[i].x >> b[i].y;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	int mx = 500;
	for (int i = 1; i <= n; ++i)
	{
		printf("6\n");
		printf("%d %d\n", a[i].x, a[i].y);
		printf("%d %d\n", a[i].x, mx);
		printf("%d %d\n", -mx, mx);
		printf("%d %d\n", -mx, -mx);
		printf("%d %d\n", b[i].x, -mx);
		printf("%d %d\n", b[i].x, b[i].y);
		mx++;
	}
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}