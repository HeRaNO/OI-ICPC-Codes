//Code By HeRaNO
#include <cstdio>
using namespace std;
int n, m, sum;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = n; i <= m; i++)
		if (!(i % 17)) sum += i;
	printf("%d", sum);
	return 0;
}
