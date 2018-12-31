#include <cstdio>
using namespace std;

inline int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int T, t, m, cnt, r;

void dfs(int dep, int p)
{
	if (dep == t)
	{
		if (p == m) ++cnt;
		return ;
	}
	dfs(dep + 1, p - 1);
	dfs(dep + 1, p + 1);
	return ;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cnt = 0;
		scanf("%d %d", &t, &m);
		r = 1 << t;
		dfs(0, 0);
		int q = gcd(cnt, r);
		cnt /= q;
		r /= q;
		if (cnt == 0) printf("0\n");
		else if (cnt == r) printf("1\n");
		else printf("%d/%d\n", cnt, r);
	}
	return 0;
}
