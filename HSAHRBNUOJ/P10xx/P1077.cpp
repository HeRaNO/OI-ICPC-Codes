#include <cstdio>
#include <climits>
#define MAXN 300010
using namespace std;

int n, a[MAXN];
int dp[MAXN];
long long ans;

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int binary(int x)
{
	int left = 0, right = ans, middle;
	while (left < right)
	{
		middle = (left + right) >> 1;
		if (dp[middle] <= x) left = middle + 1;
		else right = middle;
	}
	return left;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	dp[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= dp[ans]) dp[++ans] = a[i];
		else dp[binary(a[i])] = a[i];
	}
	printf("%lld\n", ans);
	return 0;
}
