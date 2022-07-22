#include <cstdio>
#include <vector>

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<std::vector<double>> f(n + 1, std::vector<double>(n + 1, 0));
	for (int i = 0; i <= n; i++) f[n][i] = 1;
	for (int i = n - 1; i >= 0; i--)
		for (int j = n - 1; j >= 0; j--)
			for (int l = 1; l / 2 <= n; l <<= 1)
			{
				int k = i + l;
				if (k > n) k = n;
				double t = (f[k][j + 1] + f[k][j] + f[i][j + 1] * (2 * l - 1)) / (4 * l);
				f[i][j] = std::max(f[i][j], t / (1.0 - (2 * l - 1.0) / (4 * l)));
			}
	printf("%.6lf\n", f[0][0]);
	return 0;
}