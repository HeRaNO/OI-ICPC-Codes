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
int S;
char s[50][50];

inline void solve()
{
	memarray(s, 0);
	scanf("%d", &S);
	if (S == 0)
		return printf("1 1\n.\n"), void();
	if (S == 1)
		return printf("1 2\nX.\n"), void();
	if (S == 2)
		return printf("1 3\n.X.\n"), void();
	if (S == 3)
		return printf("2 2\nX.\n..\n"), void();
	if (S == 4)
		return printf("2 2\nXX\n..\n"), void();
	if (S == 5)
		return printf("2 3\n.X.\n...\n"), void();
	if (S == 6)
		return printf("2 3\n.X.\n..X\n"), void();
	if (S == 7)
		return printf("3 2\nX.\nX.\nX.\n"), void();
	if (S == 8)
		return printf("3 3\n...\n.X.\n...\n"), void();
	if (S == 9)
		return printf("3 3\n..X\n.X.\n...\n"), void();
	if (S == 10)
		return printf("3 3\nX.X\n.X.\n...\n"), void();
	if (S == 11)
		return printf("3 3\nX.X\n.X.\nX..\n"), void();
	if (S == 12)
		return printf("3 3\nX.X\n...\nX.X\n"), void();
	if (S == 13)
		return printf("3 4\nX.X.\n.X..\nX...\n"), void();
	if (S == 14)
		return printf("3 4\n....\n.XX.\n....\n"), void();
	if (S == 15)
		return printf("4 4\nX...\n.X..\n..X.\n....\n"), void();
	if (S == 23)
		return printf("3 5\nX....\n.X.X.\n.X.X.\n"), void();
	int n = 0, m = 0;
	int cnt = S / 8;
	m = min(25, cnt * 2 + 1);
	for (n = 3; n <= 25; n += 2)
	{
		if (8 * (n / 2) * (m / 2) >= S)
			break;
	}
	int nn = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (!(i & 1) && !(j & 1) && S >= 8)
			{
				s[i][j] = 'X';
				S -= 8;
				nn = max(nn, i + 1);
			}
			else
				s[i][j] = '.';
		}
	for (int i = 1; i <= nn && S; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (S && (i & 1) && (j == 1 || j == m || i == 1 || i == n) && (j & 1))
			{
				s[i][j] = 'X';
				S--;
			}
			else if (S == 0)
			{
				// nn = max(nn, i);
				break;
			}
		}
	for (int j = 1; j <= m; ++j)
	{
		if (S && (j & 1) && s[nn][j] == '.')
		{
			S--;
			s[nn][j] = 'X';
		}
	}
	n = nn;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; ++i, puts(""))
		printf("%s", s[i] + 1);
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