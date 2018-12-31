//Code By HeRaNO
#include <stdio.h>
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int i = 2;
	while (!(a % i == b % i && b % i == c % i)) i++;
	printf("%d\n", i);
	return 0;
}
