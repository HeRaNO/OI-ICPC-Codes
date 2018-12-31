#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5010
using namespace std;

const int P = 8;
const long long BASE = 1e8;

struct bign
{
	long long s[MAXN];
	bign()
	{
		memset(s, 0, sizeof s);
	}
	bign(char *ss, int len)
	{
		int t = 0;
		memset(s, 0, sizeof s);
		for (int i = 0, w; i < len; w *= 10, i++)
		{
			if (i % P == 0)
			{
				w = 1;
				t++;
			}
			s[t] += w * (ss[i] - '0');
		}
		s[0] = t;
	}
	void print()
	{
		printf("%lld", s[s[0]]);
		for (int i = s[0] - 1; i; i--) printf("%0*lld", P, s[i]);
		puts("");
	}
};

__attribute__((__optimize__("-O2"))) void operator * (const bign &a, const bign &b)
{
	bign c;
	c.s[0] = a.s[0] + b.s[0] - 1;
	for (int i = 1; i <= a.s[0]; i++)
		for (int j = 1; j <= b.s[0]; j++)
			c.s[i + j - 1] += a.s[i] * b.s[j];
	for (int i = 1; i <= c.s[0]; i++)
		if (c.s[i] >= BASE)
		{
			c.s[i + 1] += c.s[i] / BASE;
			c.s[i] %= BASE;
		}
	if (c.s[c.s[0] + 1]) c.s[0]++;
	c.print();
	return ;
}

int T, slen, tlen;
char s[MAXN], t[MAXN];
bign a, b, c;

__attribute__((__optimize__("-O2"))) int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		scanf("%s", t);
		slen = strlen(s);
		tlen = strlen(t);
		reverse(s, s + slen);
		reverse(t, t + tlen);
		a = bign(s, slen);
		b = bign(t, tlen);
		a *b;
	}
	return 0;
}
