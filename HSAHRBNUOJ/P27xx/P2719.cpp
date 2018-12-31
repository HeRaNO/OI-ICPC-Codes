#include <cstdio>
using namespace std;

int n, u, v, l, r, x;
long long ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &x);
	l = r = x;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &u, &v);
		if (mymax(l, u) <= mymin(r, v))
		{
			l = mymax(l, u);
			r = mymin(r, v);
		}
		else if (v < l)
		{
			ans += (l - v);
			r = l;
			l = v;
		}
		else
		{
			ans += (u - r);
			l = r;
			r = u;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
