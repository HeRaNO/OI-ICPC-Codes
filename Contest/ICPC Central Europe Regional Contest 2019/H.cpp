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
const int N = 1000050;
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
map<string, int> s;
char s1[N], s2[N];
int ans;
int a[5][5];
int b[5];
inline int id(char c)
{
	if (c == 'A')
		return 0;
	if (c == 'G')
		return 1;
	if (c == 'C')
		return 2;
	if (c == 'T')
		return 3;
}

void solve()
{
	scanf("%s", s1);
	scanf("%s", s2);
	n = strlen(s1 + 1);
	for (int i = 0; i < n; ++i)
		a[id(s1[i])][id(s2[i])]++;
	for (int k = 2; k <= 4; ++k)
	{
		for (int i = 0; i < 4; ++i)
			b[i] = i;
		do
		{
			int tmp = inf;
			for (int i = 0; i < k; ++i)
				tmp = min(tmp, a[b[i]][b[(i + 1) % k]]);
			n -= tmp;
			for (int i = 0; i < k; ++i)
				a[b[i]][b[(i + 1) % k]] -= tmp;
		} while (next_permutation(b, b + 4));
	}
	for (int i = 0; i < 4; ++i)
		n -= a[i][i];
	cout << n << '\n';
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