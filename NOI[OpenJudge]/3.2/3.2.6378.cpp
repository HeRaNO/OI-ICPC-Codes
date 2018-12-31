//Code By HeRaNO
#include <cstdio>
using namespace std;

long long a[200005];
int n, m;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++)
		if (a[i] != m) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
