#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;

char s[MAXN];
int next[MAXN];
int len;
int cas = 1;

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
	while (scanf("%d", &len) != EOF && len)
	{
		scanf("%s", s);
		getnext(s);
		printf("Test case #%d\n", cas);
		cas++;
		int length;
		for (int i = 1; i <= len ; i++)
		{
			length = i - next[i];
			if (i != length && !(i % length))
				printf("%d %d\n", i, i / length);
		}
		printf("\n");
	}
	return 0;
}
