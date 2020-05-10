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
char s[N];
int tot1, tot2;
pair<int, int> h[] = {{1, 1}, {1, 3}, {2, 1}, {2, 3}};
pii w[] = {{3, 1}, {3, 2}, {3, 3}, {3, 4}};
int nxt(int x)
{
	x = (x + 1) % 4;
	return x;
}

void solve()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
	{
		if(s[i]=='0')
		{
			printf("%d %d\n", w[tot1].first, w[tot1].second);
			tot1 = nxt(tot1);
		}
		else
		{
			printf("%d %d\n", h[tot2].first, h[tot2].second);
			tot2 = nxt(tot2);
		}
	}
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
