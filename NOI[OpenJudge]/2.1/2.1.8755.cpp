//Code By HeRaNO
#include<cstdio>
#include<cstring>
int f[100010];
int a[7];
int b[] = {0, 1, 2, 3, 5, 10, 20};
int sum = 0, i, j, k, ans = 0;
int main()
{
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= 6; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i] * b[i];
	}
	f[0] = 1;
	for (i = 1; i <= 6; i++)
		for (j = 1; j <= a[i]; j++)
			for (k = sum; k >= b[i]; k--)
				if (f[k - b[i]]) f[k] = 1;
	for (i = 0; i <= sum; i++)
		if (f[i]) ans++;
	printf("Total=%d", ans - 1);
	return 0;
}
