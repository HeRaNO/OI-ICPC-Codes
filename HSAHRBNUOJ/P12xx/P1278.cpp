#include <cstdio>
#include <iostream>
using namespace std;

int n, i, k, j, x;
int f[101];

int main()
{
	fill(f, f + 101, 1);
	scanf("%d %d", &n, &k);
	for (i = 1; i <= k; i++)
	{
		scanf("%d", &x);
		f[x] = 0;
	}
	if (f[1] != 0) f[1] = 1;
	if (f[2] != 0) f[2] = f[1] + 1;
	if (f[3] != 0) f[3] = f[1] + f[2] + 1;
	for (i = 4; i <= n; i++)
		if (f[i] != 0)
			f[i] = f[i - 3] + f[i - 2] + f[i - 1];
	printf("%d\n", f[n]);
	return 0;
}
