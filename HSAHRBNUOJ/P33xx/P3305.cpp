#include <cstdio>
#include <cstring>
#define MAXN 10010
#define MAXL 110
#define MOD 1000000007LL
using namespace std;

int n, len;
char s[MAXL];
int nxt[MAXL];
long long dp[MAXN][MAXL], ans, x;
int trans[MAXN][26];

inline void KMP()
{
	for (int i = 2; i <= len; i++)
	{
		int p = nxt[i - 1];
		while (p && s[p + 1] != s[i]) p = nxt[p];
		if (s[p + 1] == s[i]) nxt[i] = p + 1;
	}
	return ;
}

int main()
{
	while (~scanf("%d", &n))
	{
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1LL;
		memset(nxt, 0, sizeof nxt);
		ans = 0LL;
		x = 1LL;
		memset(trans, -1, sizeof trans);
		memset(trans[0], 0, sizeof(trans[0]));
		memset(s, 0, sizeof s);
		scanf("%s", s + 1);
		len = strlen(s + 1);
		KMP();
		for (int i = 0; i < len; i++) trans[i][s[i + 1] - 'a'] = i + 1;
		for (int i = 0; i <= len; i++)
			for (int j = 0; j < 26; j++)
				if (trans[i][j] == -1) trans[i][j] = trans[nxt[i]][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < len; j++)
				for (int k = 0; k < 26; k++)
					dp[i + 1][trans[j][k]] = (dp[i + 1][trans[j][k]] + dp[i][j]) % MOD;
		for (int i = n; ~i; i--)
		{
			ans = (ans + x * dp[i][len]) % MOD;
			if (i) x = (x * 26) % MOD;
		}
		printf("%lld\n", (x - ans + MOD) % MOD);
	}
	return 0;
}
