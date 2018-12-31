#include <cstdio>
#define MAXN 100010
using namespace std;

int n, T, x, i;
int a[MAXN];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			a[x] = i;
		}
		for (i = n; i > 1; i--) if (a[i] < a[i - 1]) break;
		printf("%d\n", i - 1);
	}
	return 0;
}
