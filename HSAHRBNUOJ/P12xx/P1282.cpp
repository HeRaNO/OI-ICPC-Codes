#include <cstdio>
using namespace std;

int f[30], a, n, m, x;

int main()
{
	scanf("%d %d %d %d", &a, &n, &m, &x);
	f[1] = f[2] = 1;
	for (int i = 3; i < n; i++) f[i] = f[i - 1] + f[i - 2];
	int p = (f[x - 1] - 1) * (m - (f[n - 3] + 1) * a), q = f[n - 2] - 1;
	if (!q || p % q)
	{
		printf("No answer.\n");
		return 0;
	}
	printf("%d\n", (f[x - 2] + 1)*a + p / q);
	return 0;
}