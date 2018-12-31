#include <cstdio>
#define MAXN 10010
using namespace std;

int n, ans;
int a[MAXN], pos[MAXN], neg[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	pos[1] = a[1];
	neg[n] = a[n];
	for (int i = 2; i <= n; i++) pos[i] = mymax(pos[i - 1], a[i]);
	for (int i = n - 1; i; i--) neg[i] = mymax(neg[i + 1], a[i]);
	for (int i = 1; i <= n; i++) ans += mymin(pos[i], neg[i]) - a[i];
	printf("%d\n", ans);
	return 0;
}
