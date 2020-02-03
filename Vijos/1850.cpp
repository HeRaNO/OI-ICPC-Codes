#include<cstdio>
#include<cstring>
using namespace std;

long long mymax(long long x, long long y)
{
	return x > y ? x : y;
}
long long n, p, a[1100000];
long long b[1100000], c[1100000];

int main()
{
	int i, j;
	scanf("%lld%lld", &n, &p);
	for (i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	b[1] = a[1];
	long long now = mymax(a[1], 0);
	for (i = 2; i <= n; i++)
	{
		b[i] = b[i - 1];
		now += a[i];
		b[i] = mymax(now, b[i]);
		if (now < 0)now = 0;
	}
	c[1] = b[1], c[2] = c[1] + b[1];
	bool ok = 0;
	long long tmp = c[1];
	for (i = 2; i < n; i++)
	{
		tmp += mymax(b[i], 0);
		if (tmp >= 0)
		{
			ok = 1;
			break;
		}
	}
	for (i = 3; i <= n; i++)c[i] = (c[i - 1] + mymax(b[i - 1], 0)) % p;
	if (ok)printf("%d\n", int(c[n]));
	else printf("%d\n", int(c[1] % p));
	return 0;
}