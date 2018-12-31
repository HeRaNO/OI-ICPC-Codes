//Code By HeRaNO
#include <stdio.h>
int main()
{
	int n, i;
	float sum = 0.0;
	scanf("%d", &n);
	int a[n];
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] % 70 == 0) a[i] = a[i] / 70;
		else a[i] = a[i] / 70 + 1;
		sum = sum + a[i] * 0.1;
	}
	printf("%0.1f", sum);
	return 0;
}

