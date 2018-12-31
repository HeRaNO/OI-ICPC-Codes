#include <cmath>
#include <cstdio>
#define MAXN 15
using namespace std;

int l, r, a[MAXN], f[MAXN][10];

inline void Pre()
{
	for (int i = 0; i <= 9; i++) f[1][i] = 1LL;
	for (int i = 2; i <= 10; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= 9; k++)
				if (abs(j - k) >= 2) f[i][j] += f[i - 1][k];
	return ;
}

inline long long DP(long long x)
{
	int lt = 0;
	long long ans = 0LL;
	while (x)
	{
		a[++lt] = x % 10;
		x /= 10;
	}
	for (int i = 1; i < lt; i++)
		for (int j = 1; j <= 9; j++)
			ans += f[i][j];
	for (int i = 1; i < a[lt]; i++) ans += f[lt][i];
	for (int i = lt - 1; i; i--)
	{
		for (int j = 0; j < a[i]; j++)
			if (abs(a[i + 1] - j) >= 2) ans += f[i][j];
		if (abs(a[i + 1] - a[i]) < 2) break;
		if (i == 1) ++ans;
	}
	return ans;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	Pre();
	read(l);
	read(r);
	printf("%d\n", DP(r) - DP(l - 1));
	return 0;
}
