#include <cstdio>
using namespace std;

long long n, m;
int ncnt2, ncnt3, mcnt2, mcnt3, ans;

int main()
{
	scanf("%lld %lld", &n, &m);
	if (!n || !m)
	{
		if (n == m) puts("0");
		else puts("-1");
		return 0;
	}
	while (!(n & 1))
	{
		n >>= 1LL;
		++ncnt2;
	}
	while (n % 3LL == 0)
	{
		n /= 3LL;
		++ncnt3;
	}
	while (!(m & 1))
	{
		m >>= 1LL;
		++mcnt2;
	}
	while (m % 3LL == 0)
	{
		m /= 3LL;
		++mcnt3;
	}
	if (n != m)
	{
		puts("-1");
		return 0;
	}
	if (ncnt2 < mcnt2)
	{
		puts("-1");
		return 0;
	}
	if (ncnt3 > mcnt3)
	{
		puts("-1");
		return 0;
	}
	ans = ncnt2 - mcnt2 + mcnt3 - ncnt3;
	if (ans > 40) puts("-1");
	else printf("%d\n", ans);
	return 0;
}