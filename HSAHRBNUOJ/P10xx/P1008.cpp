#include <cstdio>
#include <cstring>
#define MAXN 2510
using namespace std;

int n, d, fh, fj;
int a[MAXN], b[MAXN], dp[MAXN];
char flag;

inline int myabs(int a)
{
	return a > 0 ? a : -a;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	memset(dp, 0x7f, sizeof dp);
	dp[0] = 0;
	read(n);
	read(d);
	for (int i = 1; i <= n; i++)
	{
		flag = getchar();
		getchar();
		if (flag == 'H') fh++;
		else fj++;
		a[i] = fh;
		b[i] = fj;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (myabs((a[i] - a[j]) - (b[i] - b[j])) <= d || a[i] == a[j] || b[i] == b[j])
				dp[i] = mymin(dp[i], dp[j] + 1);
	printf("%d\n", dp[n]);
	return 0;
}
