#include <cstdio>
#include <cstring>
#define MAXN 1010
#define MAXM 1010
using namespace std;

int n, m;
long long clim[MAXN], rlim[MAXM];
bool a[MAXN];
long long ans1, ans2;

long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	//freopen("neighbor.in","r",stdin);freopen("neighbor.out","w",stdout);
	scanf("%d %d", &n, &m);
	memset(a, false, sizeof a);
	for (int i = 1; i <= n; i++) scanf("%lld", &clim[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &rlim[i]);
	for (int i = 1; i <= n; i++) ans1 += clim[i];
	for (int i = 1; i <= m; i++) ans1 += rlim[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (a[j]) continue;
			if (rlim[j] == clim[i])
			{
				a[j] = true;
				ans1 -= rlim[j];
				break;
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans2 += mymin(clim[i], rlim[j]);
	printf("%lld %lld\n", ans1, ans2);
	return 0;
}
