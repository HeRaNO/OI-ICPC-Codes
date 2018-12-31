#include <cstdio>
#define MAXL 10100
#define MAXW 1010
using namespace std;

int w, l, ans;
int a[MAXL][MAXW];
int dp[MAXL][MAXW];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

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

int main()
{
	//freopen("azshara.in","r",stdin);freopen("azshara.out","w",stdout);
	read(w);
	read(l);
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= w; j++)
			read(a[i][j]);
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= w; j++)
			if (a[i][j] != -1)
			{
				dp[i][j] = mymax(dp[i - 1][j], mymax(dp[i - 1][j - 1], dp[i - 1][j + 1])) + a[i][j];
				ans = mymax(ans, dp[i][j]);
			}
	printf("%d\n", ans);
	return 0;
}
