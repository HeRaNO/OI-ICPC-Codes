#include <cstdio>

bool f(int x)
{
	if (!(x / 10))
	{
		if (x != 4) return false;
		else return true;
	}
	if (x % 10 == 4) return true;
	else return f(x / 10);
}

int main()
{
	int n, pt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		pt++;
		while (f(pt)) pt++;
	}
	printf("%d\n", pt);
	return 0;
}