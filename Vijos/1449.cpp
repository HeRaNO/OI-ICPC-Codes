#include <cstdio>
#include <cstdlib>
#define MAXN 10010
using namespace std;

char a[MAXN], b[MAXN], c[MAXN];
int len;

void check(char *a, char *b, char *c)
{
	for (int i = 0; i < len; i++)
	{
		int aa = a[len - i - 1], bb = b[i], cc = c[i];
		if (aa > cc) cc += 26;
		if (bb > cc) bb -= 26;
		if (cc - aa != aa - bb) return ;
	}
	for (int i = len - 1; ~i; i--) putchar(a[i]);
	putchar('\n');
	exit(0);
}

int main()
{
	scanf("%d", &len);
	scanf("%s", a);
	scanf("%s", b);
	scanf("%s", c);
	check(a, b, c);
	check(a, c, b);
	check(b, a, c);
	check(b, c, a);
	check(c, a, b);
	check(c, b, a);
	return 0;
}