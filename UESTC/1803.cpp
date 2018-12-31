#include <cstdio>
#define MAXN 100005
using namespace std;

int n, x, a[MAXN];
long long ans;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(x);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;
		if (a[i] >= a[x]) ans += a[i] - a[x] + 1;
	}
	printf("%lld\n", ans);
	return 0;
}