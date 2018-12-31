#include <cstdio>
#include <algorithm>
#define MAXN 1000010
using namespace std;

struct tree
{
	int h;
	int id;
};

int n, T, x, ans = 1, pos = 1;
tree a[MAXN];
bool del[MAXN];

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

bool cmp(tree a, tree b)
{
	return a.h > b.h;
}

int main()
{
	read(n);
	read(T);
	for (int i = 1; i <= n; i++)
	{
		read(a[i].h);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	del[0] = true;
	del[n + 1] = true;
	while (T--)
	{
		read(x);
		for (int i = pos; i < pos + x; i++)
		{
			if (!del[a[i].id - 1] && !del[a[i].id + 1]) ans++;
			if (del[a[i].id - 1] && del[a[i].id + 1]) ans--;
			del[a[i].id] = true;
		}
		pos += x;
		printf("%d\n", ans);
	}
	return 0;
}
