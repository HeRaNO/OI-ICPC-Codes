//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 3010
using namespace std;

int n;
int a[MAXN], gap[MAXN];

int myabs(int a)
{
	return a < 0 ? -a : a;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) gap[i] = myabs(a[i] - a[i - 1]);
	sort(gap + 2, gap + n + 1);
	for (int i = 2; i <= n; i++)
		if (gap[i] + 1 != i)
		{
			printf("Not jolly");
			return 0;
		}
	printf("Jolly");
	return 0;
}
