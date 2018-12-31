#include <cstdio>
#include <cstring>
#define MAXN 10000010
using namespace std;

char s[MAXN];
int next[MAXN];
int len;

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
	while (scanf("%s", s) != EOF && s[0] != '.')
	{
		memset(next, 0, sizeof(next));
		len = strlen(s);
		getnext(s);
		int tmp = len - next[len];
		if (!(len % tmp)) printf("%d\n", len / tmp);
		else printf("1\n");
		memset(s, 0, sizeof(s));
	}
	return 0;
}
