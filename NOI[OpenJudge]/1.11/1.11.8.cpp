//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

int a[MAXN], n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1]) continue;
		printf("%d ", a[i]);
	}
	return 0;
}
