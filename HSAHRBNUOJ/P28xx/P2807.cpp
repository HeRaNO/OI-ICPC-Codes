#include <cstdio>
#include <algorithm>
#define MAXN 55
#define MAXL 1000
using namespace std;

struct tower
{
	int x, y;
};

tower a[MAXN];
long long ans[MAXL];
long long dis[MAXL];
int n;

inline int myabs(int a)
{
	return a > 0 ? a : -a;
}
inline long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}
inline int getdis(tower a, tower b)
{
	return myabs(a.x - b.x) + myabs(a.y - b.y);
}

int main()
{
	//freopen("tower.in","r",stdin);freopen("tower.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= 50; i++) ans[i] = 1e18;
	for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].x, &a[i].y);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			tower s = (tower)
			{
				a[i].x, a[j].y
			};
			long long sum = 0LL;
			for (int k = 1; k <= n; k++) dis[k] = getdis(s, a[k]);
			sort(dis + 1, dis + n + 1);
			for (int k = 1; k <= n; k++)
			{
				sum += dis[k];
				ans[k] = mymin(ans[k], sum);
			}
		}
	for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
	return 0;
}
