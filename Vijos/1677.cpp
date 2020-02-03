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
	scanf("%s", s);
	len = strlen(s);
	getnext(s);
	int tmp = len, ans = len;
	while (next[tmp]) tmp--;
	while (next[ans] >= tmp) ans = next[ans];
	printf("%d\n", ans);
	return 0;
}