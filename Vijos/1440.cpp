#include <cstdio>
#include <algorithm>
#define MAXN 10010
using namespace std;

int x[MAXN], y[MAXN];
int n, ans, s1, s2;

inline int myabs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (int i = 1; i <= n; i++) x[i] = x[i] - i + 1;
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++) ans = ans + myabs(x[i] - x[(n >> 1) + 1]) + myabs(y[i] - y[(n >> 1) + 1]);
	printf("%d\n", ans);
	return 0;
}