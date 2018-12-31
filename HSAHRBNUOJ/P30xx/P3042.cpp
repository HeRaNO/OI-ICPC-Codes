#include <cstdio>
using namespace std;
int main()
{
	int n;
	long long ans = 0;
	scanf("%d", &n);
	while (n >= 5)
	{
		n /= 5;
		ans += n;
	}
	printf("%lld\n", ans);
	return 0;
}