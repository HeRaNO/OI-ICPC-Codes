//Code By HeRaNO
#include<stdio.h>
int main()
{
	int r, h, t;
	scanf("%d %d", &h, &r);
	t = ((r * r) * 3.14159) * h;
	printf("%d", (20 * 1000) / t + 1);
	return 0;
}