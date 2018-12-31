#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;

char s[MAXN];
int next[MAXN];
int len;
int ans[MAXN];

void getnext(const char *s)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i != len)
	{
		if (j == -1 || s[i] == s[j])
			next[++i] = ++j;
		else j = next[j];
	}
	return ;
}

int main()
{
	while (scanf("%s", s) != EOF)
	{
		memset(next, 0, sizeof(next));
		len = strlen(s);
		getnext(s);
		int k = 0, i = len;
		ans[k] = len;
		while (next[i] > 0)
		{
			i = next[i];
			ans[++k] = i;
		}
		for (int pp = k; pp; pp--)
			printf("%d ", ans[pp]);
		printf("%d\n", len);
		memset(s, 0, sizeof(s));
	}
	return 0;
}
