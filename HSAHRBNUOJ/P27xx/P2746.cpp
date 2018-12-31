#include <cstdio>
#define MAXN 200010
#define MOD 1000000009
using namespace std;

int n, m;
int u, v;
int father[MAXN];
long long ans;

int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

int main()
{
	//freopen("magician.in","r",stdin);freopen("magician.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		if (getfather(u) == getfather(v)) ans = (ans * 2 + 1) % MOD;
		else father[getfather(v)] = getfather(u);
		printf("%lld\n", ans);
	}
	return 0;
}
