//Code By HeRaNO
#include <cstdio>
#define MAXN 110
using namespace std;
int c[MAXN];
int a, n;
int main()
{
	scanf("%d", &n);
	for (int i = n; ~i; i--)
		scanf("%d", &c[i]);
	if (!n) printf("0\n");
	else
	{
		for (int i = n; i; i--)
			printf("%d ", c[i]*i);
		printf("\n");
	}
	return 0;
}
