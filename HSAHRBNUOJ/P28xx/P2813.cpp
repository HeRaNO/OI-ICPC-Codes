#include <cmath>
#include <cstdio>
#include <vector>
#define N 100000
#define MAXN 100010
using namespace std;

int n, k, l = 1, K;
int a[MAXN], c[MAXN], sum[MAXN];
vector <int> table[MAXN];
long long ans = 1LL;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

int main()
{
	//freopen("drink.in","r",stdin);freopen("drink.out","w",stdout);
	n = read();
	k = read();
	K = (int)sqrt(N);
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = k + 1; i <= K; i++)
		for (int j = k; j <= N; j += i)
			table[j].push_back(i);
	c[a[1]]++;
	for (int i = 0; i < table[a[1]].size(); i++) sum[table[a[1]][i]]++;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > K && a[i] > k)
		{
			while (true)
			{
				int x = 0;
				for (int j = k; j <= N; j += a[i]) x += c[j];
				if (!x) break;
				c[a[l]]--;
				for (int j = 0; j < table[a[l]].size(); j++) sum[table[a[l]][j]]--;
				l++;
			}
			ans += (long long)(i - l + 1);
		}
		else if (a[i] > k)
		{
			while (true)
			{
				int x = sum[a[i]];
				if (!x) break;
				c[a[l]]--;
				for (int j = 0; j < table[a[l]].size(); j++) sum[table[a[l]][j]]--;
				l++;
			}
			ans += (long long)(i - l + 1);
		}
		else ans += (long long)(i - l + 1);
		c[a[i]]++;
		for (int j = 0; j < table[a[i]].size(); j++) sum[table[a[i]][j]]++;
	}
	printf("%lld\n", ans);
	return 0;
}
