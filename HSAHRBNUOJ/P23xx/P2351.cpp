#include <cstdio>
using namespace std;

int n, t, ans;
double a;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %d", &a, &t);
		for (int j = 1; j <= t; j++) ans ^= int(j * a);
	}
	printf("%d\n", ans);
	return 0;
}
