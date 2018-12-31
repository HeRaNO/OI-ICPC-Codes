#include <cstdio>
#define MAXN 1010
char cat[MAXN];
int main()
{
	freopen("copycat.in", "r", stdin);
	freopen("copycat.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", cat);
		puts(cat);
	}
	return 0;
}