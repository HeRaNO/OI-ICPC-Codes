//Code By HeRaNO
#include <cstdio>
using namespace std;
int n, a, sum = 1;
int main()
{
	scanf("%d %d", &a, &n);
	for (int i = 1; i <= n; i++)
		sum *= a;
	printf("%d", sum);
	return 0;
}
