#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;

int exnxt[MAXN], ext[MAXN];
char S[MAXN];
int n;
long long a, b, dp[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

inline void GetExtendNext(char S[])
{
	int a = 0, Slen = strlen(S);
	exnxt[0] = Slen;
	while (a < Slen && S[a] == S[a + 1]) a++;
	exnxt[1] = a;
	a = 1;
	for (int i = 2; i < Slen; i++)
	{
		int p = a + exnxt[a] - 1, l = exnxt[i - a];
		if (i - 1 + l >= p)
		{
			int j = (p - i + 1) > 0 ? p - i + 1 : 0;
			while (i + j < Slen && S[i + j] == S[j]) j++;
			exnxt[i] = j;
			a = i;
		}
		else exnxt[i] = l;
	}
	return ;
}

inline void GetExtend(char S[], char T[])
{
	int a = 0;
	GetExtendNext(T);
	int Slen = strlen(S), Tlen = strlen(T);
	int Minlen = mymin(Slen, Tlen);
	while (a < Minlen && S[a] == T[a]) a++;
	ext[0] = a;
	a = 0;
	for (int i = 1; i < Slen; i++)
	{
		int p = a + ext[a] - 1, l = exnxt[i - a];
		if (i - 1 + l >= p)
		{
			int j = (p - i + 1) > 0 ? p - i + 1 : 0;
			while (i + j < Slen && j < Tlen && S[i + j] == T[j]) j++;
			ext[i] = j;
			a = i;
		}
		else ext[i] = l;
	}
	return ;
}

int main()
{
	scanf("%s", S);
	n = strlen(S);
	scanf("%lld %lld", &a, &b);
	GetExtend(S, S);
	for (int i = n; i; i--) ext[i] = ext[i - 1];
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + a;
		if (!(i & 1) && ext[(i >> 1) + 1] >= i >> 1) dp[i] = mymin(dp[i], dp[i >> 1] + b * (i >> 1));
	}
	printf("%lld\n", dp[n]);
	return 0;
}
