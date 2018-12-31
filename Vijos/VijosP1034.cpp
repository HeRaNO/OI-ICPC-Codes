#include <cstdio>
#define MAXN 5010
using namespace std;

int n, m, T, u, v;
int father[MAXN];

int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

int main()
{
	scanf("%d %d %d", &n, &m, &T);
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		father[getfather(u)] = getfather(v);
	}
	while (T--)
	{
		scanf("%d %d", &u, &v);
		if (getfather(u) == getfather(v)) puts("Yes");
		else puts("No");
	}
	return 0;
}
