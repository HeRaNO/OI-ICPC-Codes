#include <cstdio>
#include <algorithm>
#define MAXN 1000010
using namespace std;

int n, T, opt, x, y;
int lc[MAXN], rc[MAXN], dep[MAXN], score[MAXN];
int father[MAXN];
bool dead[MAXN];

inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

int Merge(int x, int y)
{
	if (!x || !y) return x + y;
	if (score[x] > score[y]) swap(x, y);
	rc[x] = Merge(rc[x], y);
	if (dep[rc[x]] > dep[lc[x]]) swap(lc[x], rc[x]);
	dep[x] = dep[rc[x]] + 1;
	return x;
}

inline void Combine(int x, int y)
{
	if (dead[x] || dead[y]) return ;
	int fx = getfather(x), fy = getfather(y);
	if (fx != fy)
	{
		int t = Merge(fx, fy);
		father[fx] = father[fy] = t;
	}
	return ;
}

inline int Query(int x)
{
	if (dead[x]) return 0;
	int fx = getfather(x);
	dead[fx] = true;
	father[fx] = Merge(lc[fx], rc[fx]);
	father[father[fx]] = father[fx];
	return score[fx];
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'M') return ;
		if (ch == 'K')
		{
			x = 1;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(score[i]);
		father[i] = i;
	}
	read(T);
	while (T--)
	{
		read(opt);
		if (!opt)
		{
			read(x);
			read(y);
			Combine(x, y);
		}
		else
		{
			read(x);
			printf("%d\n", Query(x));
		}
	}
	return 0;
}
