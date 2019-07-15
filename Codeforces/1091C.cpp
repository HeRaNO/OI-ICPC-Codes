#include <cstdio>
#include <algorithm>
using namespace std;

int pl;
long long n, ans[100010];

int main()
{
	scanf("%I64d", &n);
	for (long long i = 1; i * i <= n; i++)
		if (!(n % i))
		{
			ans[pl++] = (n / i - 1) * n / 2 + n / i;
			ans[pl++] = (i - 1) * n / 2 + i;
		}
	sort(ans, ans + pl);
	pl = unique(ans, ans + pl) - ans;
	for (int i = 0; i < pl; i++) printf("%I64d%c", ans[i], i == pl - 1 ? '\n' : ' ');
	return 0;
}