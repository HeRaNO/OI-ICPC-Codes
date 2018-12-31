//Code By HeRaNO
#include <cstdio>

int n, m;
bool first = true;

bool is_prime(int a)
{
	if (a < 2) return false;
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0) return false;
	return true;
}

void work(int a)
{
	int res = 1;
	for (int i = 2; i <= a; i++)
	{
		if (a % i == 0 && is_prime(i))
			res = i;
	}
	if (first)
	{
		first = false;
		printf("%d", res);
		return ;
	}
	else printf(",%d", res);
	return ;
}

int  main()
{
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++)
		work(i);
	return 0;
}
