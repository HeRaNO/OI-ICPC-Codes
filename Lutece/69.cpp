#include <cstdio>
#include <iostream>
#define MAXN 1010
using namespace std;

int n, k, x, sum;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		sum += x;
	}
	printf("%d\n", max(n * k - sum, 0));
	return 0;
}
