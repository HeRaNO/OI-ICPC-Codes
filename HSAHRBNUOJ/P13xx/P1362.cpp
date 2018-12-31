#include <cstdio>

int pow[31];
int n, k, ans, t = 30;

int main()
{
	for (int i = 1; i <= 30; i++) pow[i] = 1 << i;
	scanf("%d %d", &n, &k);
	if (k >= n)
	{
		printf("%d\n", k - n);
		return 0;
	}
	for (; k; k--)
	{
		while (~t && n < pow[t]) t--;
		while (n >= pow[t]) n -= pow[t];
		if (!n) break;
	}
	if (!n) printf("0\n");
	else printf("%d\n", pow[t] - n);
	return 0;
}
