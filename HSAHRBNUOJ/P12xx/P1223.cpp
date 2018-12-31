#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;

long long a[MAXN];
int i, n;
int p = 1, q;
int sta;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	while (p <= n)
	{
		sta = a[p];
		for (i = p;; i++)
			if (sta != a[i]) break;
		printf("%d %d\n", sta, i - p);
		p = i;
	}
	return 0;
}
