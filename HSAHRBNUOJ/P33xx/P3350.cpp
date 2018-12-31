#include <cstdio>
#include <algorithm>
using namespace std;

long long a1, a2, c, ans;

int main()
{
	//freopen("seq.in","r",stdin);freopen("seq.out","w",stdout);
	scanf("%lld %lld", &a1, &a2);
	if (a1 < a2) swap(a1, a2);
	c = a1 % a2;
	while (c)
	{
		ans += a1 / a2;
		a1 = a2;
		a2 = c;
		c = a1 % a2;
	}
	ans += a1 / a2;
	ans++;
	printf("%lld\n", ans);
	return 0;
}
