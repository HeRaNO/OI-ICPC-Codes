#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

int n, k;
int heada, taila, headb, tailb;
long long a[MAXN], b[MAXN];
long long ans;

long long myabs(long long a)
{
	return a < 0 ? -a : a;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	heada = 1;
	taila = n;
	headb = 1;
	tailb = n;
	for (int i = 1; i <= k; i++)
	{
		if (myabs(a[taila] - b[headb]) > myabs(b[tailb] - a[heada]))
		{
			ans += myabs(a[taila] - b[headb]);
			taila--;
			headb++;
		}
		else
		{
			ans += myabs(b[tailb] - a[heada]);
			tailb--;
			heada++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
