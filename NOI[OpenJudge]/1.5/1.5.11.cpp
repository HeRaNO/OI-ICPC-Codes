//Code By HeRaNO
#include <cstdio>
using namespace std;
int n, m, sum1, sum5, sum10;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		if (m == 1) sum1++;
		else if (m == 5) sum5++;
		else if (m == 10) sum10++;
	}
	printf("%d\n%d\n%d\n", sum1, sum5, sum10);
	return 0;
}
