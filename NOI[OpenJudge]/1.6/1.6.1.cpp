//Code By HeRaNO
#include <cstdio>
using namespace std;
int n, m, a, sum;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if (m == a) sum++;
	}
	printf("%d", sum);
	return 0;
}

