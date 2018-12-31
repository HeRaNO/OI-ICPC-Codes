#include <cstdio>
using namespace std;

int n, x, i;
long long ans = 0;

int solve(int p, int x)
{
	int re = 0, tmpp;
	while (p)
	{
		tmpp = p;
		p = p % 10;
		if (p == x) re++;
		p = tmpp;
		p /= 10;
	}
	return re;
}

int main()
{
	//freopen("count.in","r",stdin);freopen("count.out","w",stdout);
	scanf("%d %d", &n, &x);
	for (i = 1; i <= n; i++) ans += solve(i, x);
	printf("%d\n", ans);
	return 0;
}
