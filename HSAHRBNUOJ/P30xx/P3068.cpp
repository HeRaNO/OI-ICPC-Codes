#include <cstdio>
using namespace std;

int f[100], n;
double ans;

int main()
{
	scanf("%d", &n);
	f[0] = f[1] = 1;
	for (int i = 2; i <= n + 1; i++) f[i] = f[i - 1] + f[i - 2];
	for (int i = 1; i <= n; i++) ans += (double)f[i + 1] / (double)f[i];
	printf("%.2lf\n", ans);
	return 0;
}