#include <iostream>
#include <stdio.h>
using namespace std;
int h[50010], t[50010];
int n, k;
void add(int a[], int k)
{
	while (k <= n)
	{
		a[k]++;
		k += k & (-k);
	}
}
int search(int a[], int k)
{
	int tot = 0;
	while (k)
	{
		tot += a[k];
		k -= k & (-k);
	}
	return tot;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1)
		{
			add(h, b);
			add(t, c);
		}
		else printf("%d\n", search(h, c) - search(t, b - 1));
	}
	return 0;
}