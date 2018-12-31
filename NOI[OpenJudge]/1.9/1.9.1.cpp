//Code By HeRaNO
#include<stdio.h>
int main()
{
	int n, zhao, i, xiabiao;
	scanf("%d", &n);
	int shu[n - 1];
	for (i = 0; i <= n - 1; i++) scanf("%d", &shu[i]);
	scanf("%d", &zhao);
	for (i = 0; i <= n - 1; i++)
	{
		if (shu[i] == zhao)
		{
			i++;
			printf("%d", i);
			return 0;
		}
		if (i == n - 1)
		{
			printf("-1");
			return 0;
		}
	}
}
