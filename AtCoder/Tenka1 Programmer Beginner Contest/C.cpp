#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, l, r;
long long a[100010], b[100010], ans, ans1;

int main()
{
	scanf("%d", &n);
	l = 1;
	r = n;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 2; i < n; i++) b[i] = 2;
	b[1] = b[n] = 1;
	for (int i = 1; i <= n; i++)
		if (i & 1) b[i] = -b[i];
	for (int i = 2; i < n; i++)
	{
		if (b[i] > 0) ans += a[r--] * b[i];
		else ans += a[l++] * b[i];
	}
	if (b[1] == b[n]) ans += a[l] * b[1] + a[r] * b[n];
	else ans += a[r] - a[l];
	for (int i = 1; i <= n; i++) b[i] = -b[i];
	l = 1;
	r = n;
	for (int i = 2; i < n; i++)
	{
		if (b[i] > 0) ans1 += a[r--] * b[i];
		else ans1 += a[l++] * b[i];
	}
	if (b[1] == b[n]) ans1 += a[l] * b[1] + a[r] * b[n];
	else ans1 += a[r] - a[l];
	printf("%lld\n", max(ans, ans1));
	return 0;
}