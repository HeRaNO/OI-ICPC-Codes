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
inline bool dfs(char *s1, char *s2, int n)
{
	if (strncmp(s1, s2, n) == 0)
		return true;
	if (n & 1)
		return false;
	if ((dfs(s1, s2 + n / 2, n / 2) && dfs(s1 + n / 2, s2, n / 2)) || (dfs(s1, s2, n / 2) && dfs(s1 + n / 2, s2 + n / 2, n / 2)))
		return true;
	else
		return false;
}

int n;
char s1[N], s2[N];
void solve()
{
	scanf("%s", s1);
	scanf("%s", s2);
	n = strlen(s1);
	bool flag = dfs(s1, s2, n);
	if (flag)
		puts("YES");
	else
		puts("NO");
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