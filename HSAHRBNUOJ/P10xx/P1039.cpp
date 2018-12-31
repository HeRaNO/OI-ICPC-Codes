#include <cstdio>
using namespace std;

int p, q, a, n;
long long ans;

int gcd(int m, int n)
{
	return m % n == 0 ? n : gcd(n, m % n);
}
bool judge(int a, int b, int c, int d)
{
	if (a * d > b * c) return 1;
	return 0;
}

void dfs(int zi, int mu, int dep, int now, int last)
{
	if (dep == n + 2) return;
	if (now > a) return;
	if (zi == 0)
	{
		ans++;
		return;
	}
	int u, i;
	u = a / now;
	for (i = last; i <= u; i++)
	{
		if (judge(1, i, zi, mu)) continue;
		else
		{
			long long pp, qq, o;
			qq = i * mu;
			pp = zi * i - mu;
			if (pp != 0)
			{
				o = gcd(pp, qq);
				pp /= o;
				qq /= o;
			}
			dfs(pp, qq, dep + 1, now * i, i);
		}
	}
	return ;
}

int main()
{
	scanf("%d %d %d %d", &p, &q, &a, &n);
	int i = gcd(p, q);
	p /= i;
	q /= i;
	dfs(p, q, 1, 1, 1);
	printf("%d\n", ans);
	return 0;
}
