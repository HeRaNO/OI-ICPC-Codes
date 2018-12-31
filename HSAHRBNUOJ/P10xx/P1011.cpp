#include <cstdio>
#define MAXH 2010
#define MAXN 110
using namespace std;

int h[MAXN];
int n, sum;
bool dp[MAXH][MAXH];

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
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(h[i]);
		sum += h[i];
	}
	dp[0][0] = true;
	for (int i = 1; i <= n; i++)
		for (int j = sum >> 1; ~j; j--)
			for (int k = sum >> 1; ~k; k--)
				if (dp[j][k])
					dp[j + h[i]][k] = dp[j][k + h[i]] = true;
	for (int i = sum; i; i--)
		if (dp[i][i])
		{
			printf("%d\n", i);
			return 0;
		}
	puts("Impossible");
	return 0;
}
