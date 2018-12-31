//Code By HeRaNO
#include <cstdio>
#include <climits>
using namespace std;

long long d[300000], a[300000];
long long len, i, k, n;

long long binary(long long t)
{
	long long s, w, mid;
	s = 0;
	w = len;
	while (s < w)
	{
		mid = (s + w) / 2;
		if (d[mid] <= t)
			s = mid + 1;
		else w = mid;
	}
	return s;
}

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
	len = 0;
	d[0] = INT_MIN;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > d[len])
		{
			len++;
			d[len] = a[i];
		}
		else
		{
			k = binary(a[i]);
			d[k] = a[i];
		}
	}
	printf("%lld\n", len);
	return 0;
}
