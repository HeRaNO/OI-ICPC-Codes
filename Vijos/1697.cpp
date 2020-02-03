#include <cstdio>
#include <cstring>
#define MAXN 210

int father[2 * MAXN];
int u, v;
char opt;
bool used[2 * MAXN];
int ans, n, m, T;

int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

int main()
{
	scanf("%d %d %d\n", &n, &m, &T);
	for (int i = 1; i <= 2 * n; i++) father[i] = i;
	for (int i = 1; i <= m; i++)
	{
		scanf("l%d %c l%d\n", &u, &opt, &v);
		if (opt == 'p')
		{
			if (getfather(u) != getfather(v + n) && getfather(v) != getfather(u + n))
			{
				father[getfather(u)] = getfather(v);
				father[getfather(u + n)] = getfather(v + n);
			}
			else
			{
				puts("There must be something wrong...");
				return 0;
			}
		}
		else
		{
			if (getfather(u) != getfather(v) && getfather(v + n) != getfather(u + n))
			{
				father[getfather(u)] = getfather(v + n);
				father[getfather(v)] = getfather(u + n);
			}
			else
			{
				puts("There must be something wrong...");
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (getfather(i) == getfather(j) && !used[j])
			{
				used[j] = true;
				ans++;
			}
			if (getfather(i) == getfather(j + n))
			{
				for (int k = j + 1; k <= n; k++)
					if (getfather(k) == getfather(j + n) && !used[k])
					{
						ans++;
						used[k] = true;
					}
			}
		}
		memset(used, false, sizeof used);
	}
	printf("%d\n", ans);
	while (T--)
	{
		scanf("l%d l%d\n", &u, &v);
		if (getfather(u) == getfather(v)) puts("Parallel.");
		else if (getfather(u) == getfather(n + v)) puts("Vertical.");
		else puts("No idea.");
	}
	return 0;
}
