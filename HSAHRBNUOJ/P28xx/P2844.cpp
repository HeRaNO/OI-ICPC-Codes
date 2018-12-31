#include <cstdio>
#include <algorithm>
#define MAXN 310
#define MAXM 44851
using namespace std;

struct link
{
	int from;
	int to;
	int val;
};

link e[MAXM];
int n, m, ans;
int father[MAXN];

inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}
inline bool cmp(link a, link b)
{
	return a.val < b.val;
}
inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(m);
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= m; i++) read(e[i].from), read(e[i].to), read(e[i].val);
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		int x = getfather(e[i].from), y = getfather(e[i].to);
		if (x != y)
		{
			father[y] = x;
			ans = e[i].val;
		}
	}
	printf("%d %d\n", n - 1, ans);
	return 0;
}
