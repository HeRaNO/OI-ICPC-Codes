//Code By HeRaNO
#include <stdio.h>
int main()
{
	long x;
	int i;
	int a[32];
	scanf("%ld", &x);
	if (x < 0)
	{
		x += 2147483648;
		a[0] = 1;
	}
	else
		a[0] = 0;
	for (i = 31; i > 0; --i)
	{
		a[i] = x % 2;
		x /= 2;
	}
	for (i = 0; i < 32; ++i)
		printf("%d", a[i]);
	return 0;
}
