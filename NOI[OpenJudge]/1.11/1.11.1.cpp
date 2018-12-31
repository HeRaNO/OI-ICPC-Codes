//Code By HeRaNO
#include <cstdio>
#define MAXN 100010
using namespace std;

int n, t, q;
int a[MAXN];

int binary(int x)
{
	int left = 0, right = n, middle;
	while (left + 1 != right)
	{
		middle = (right + left) >> 1;
		if (a[middle] == x) return a[middle];
		else if (a[middle] < x) left = middle;
		else right = middle;
	}
	if (!left) return a[right];
	if (x - a[left] > a[right] - x) return a[right];
	else return a[left];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &q);
		printf("%d\n", binary(q));
	}
	return 0;
}
