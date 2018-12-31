//Code By HeRaNO
#include <cstdio>
using namespace std;
int n, i, j;
int main()
{
	scanf("%d %d %d", &n, &i, &j);
	for (int a = 1; a <= n; a++)
		printf("(%d,%d) ", i, a);
	printf("\n");
	for (int a = 1; a <= n; a++)
		printf("(%d,%d) ", a, j);
	printf("\n");
	for (int a = 1; a <= n; a++)
		for (int b = 1; b <= n; b++)
			if (b - a == j - i) printf("(%d,%d) ", a, b);
	printf("\n");
	for (int a = n; a; a--)
		for (int b = 1; b <= n; b++)
			if (a + b == i + j) printf("(%d,%d) ", a, b);
	printf("\n");
	return 0;
}
