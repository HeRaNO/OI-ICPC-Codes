#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100010];
int p, q, r, s;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	printf("%d\n", min(a[n] - a[2], a[n - 1] - a[1]));
	return 0;
}