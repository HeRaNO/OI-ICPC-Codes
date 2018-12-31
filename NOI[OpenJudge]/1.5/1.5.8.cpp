//Code By HeRaNO
#include <cstdio>
using namespace std;
int sum, a, n;
int main()
{
	scanf("%d", &n);
	sum = 180 * (n - 2);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a);
		sum -= a;
	}
	printf("%d", sum);
	return 0;
}
