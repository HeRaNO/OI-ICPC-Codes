#include <stdio.h>

int n, L, l, r, a[10001], ans;

int main()
{
	scanf("%d%d", &L, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &l, &r);
		for (int j = l; j <= r; j++) ++a[j];
	}
	for (int i = 0; i <= L; i++) if (!a[i]) ++ans;
	printf("%d\n", ans);
	return 0;
}
