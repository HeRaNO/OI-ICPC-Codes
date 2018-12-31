#include <cstdio>
#include <cstring>
#define MAXS 2010
#define MAXP 510
using namespace std;

char s[MAXS], p[MAXP];
int w[MAXS];
int dp[MAXS][MAXS];
int slen, plen;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%s", s);
	scanf("%s", p);
	slen = strlen(s);
	plen = strlen(p);
	for (int i = 0; i < slen; i++)
	{
		int pos = i;
		w[i] = 0;
		for (int j = 0; j < plen; j++)
		{
			while (s[pos] != p[j] && pos < slen) pos++;
			if (pos >= slen) break;
			pos++;
			if (j == plen - 1) w[i] = pos - i;
		}
	}
	for (int i = 0; i < slen; i++)
		for (int j = 0; j <= i; j++)
		{
			dp[i + 1][j] = mymax(dp[i][j], dp[i + 1][j]);
			dp[i + 1][j + 1] = mymax(dp[i][j], dp[i + 1][j + 1]);
			if (w[i]) dp[i + w[i]][j + w[i] - plen] = mymax(dp[i][j] + 1, dp[i + w[i]][j + w[i] - plen]);
		}
	for (int i = 0; i <= slen; i++) printf("%d ", dp[slen][i]);
	//printf("%d\n",dp[slen][slen]);
	return 0;
}
