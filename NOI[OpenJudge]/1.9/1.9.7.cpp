//Code By HeRaNO
#include<stdio.h>
int main()
{
	int n, i, Firstmax, sum = 0;
	scanf("%d", &n);
	int shu[n - 1];
	for (i = 0; i <= n - 1; i++)
		scanf("%d", &shu[i]);
	Firstmax = shu[0];
	for (i = 1; i <= n - 1; i++)
	{
		if (shu[i] > Firstmax)
			Firstmax = shu[i];
	}
	for (i = 0; i <= n - 1; i++)
	{
		if (shu[i] != Firstmax)
			sum = sum + shu[i];
	}
	printf("%d", sum);
}
