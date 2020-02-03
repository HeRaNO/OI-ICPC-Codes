#include <stdio.h>
int main()
{
	int a[11], i, k, f = 0;
	for (i = 1; i <= 10; i++) scanf("%d", &a[i]);
	scanf("%d", &k);
	for (i = 1; i <= 10; i++)
		if (a[i] <= k + 30) f++;
	printf("%d", f);
	return 0;
}
