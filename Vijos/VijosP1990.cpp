#include <cstdio>
#define MAXN 500010
#define MOD 1000000009
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXN];
int n, t[MAXN];
long long dp[MAXN];
char s[MAXN], c;
int edge_num[MAXN];
long long sum;
int q, cnt;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline void update(long long &x)
{
	if (x < MOD) x += MOD;
	if (x >= MOD) x -= MOD;
}

void add(int u, int v)
{
	if (u > n) return ;
	e[++cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt;
}

void clean(int x)
{
	for (int i = edge_num[x]; i; i = e[i].nxt)
	{
		if (e[i].to >= q) sum -= dp[e[i].to];
		dp[e[i].to] = 0;
	}
}

int main()
{
	c = getchar();
	while (c == 'B' || c == 'W' || c == '?')s[++n] = c, c = getchar();
	if (n & 1)
	{
		puts("0");
		return 0;
	}
	t[n] = n + 1;
	for (int i = n - 1; ~i; i--)
	{
		if (s[i + 1] == 'W') t[i] = i + 1;
		else t[i] = t[i + 1];
	}
	for (int i = 0; i <= n; i += 2) add(t[i] + t[i] - i, i);
	dp[0] = sum = 1LL;
	for (int i = 2; i <= n; i += 2)
	{
		clean(i - 1);
		clean(i);
		if (s[i] == 'B')
		{
			q = i;
			sum = 0;
		}
		else if (s[i - 1] == 'B')
		{
			q = i - 2;
			sum = dp[i - 1] + dp[i - 2];
			update(sum);
		}
		else
		{
			if (q >= 1) sum += dp[q - 1];
			update(sum);
			if (q >= 2) sum += dp[q - 2];
			update(sum);
			q = mymax(0, q - 2);
		}
		dp[i] = sum;
		sum += dp[i];
		update(sum);
	}
	printf("%lld\n", dp[n] % MOD);
	return 0;
}