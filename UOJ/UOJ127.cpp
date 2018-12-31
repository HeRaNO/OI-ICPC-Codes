#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

int n, T, m, cnt1, cnt2, p, q, r;
int conflict[MAXN][2], same[MAXN][2];
int father[MAXN], ori[MAXN << 1];
pair <int, int *> b[MAXN << 1];

inline void Discretization()
{
	m = 0;
	sort(b + 1, b + n * 2 + 1);
	for (int i = 1; i <= n << 1; i++)
	{
		if (b[i].first != b[i - 1].first) ori[++m] = b[i].first;
		*b[i].second = m;
	}
	return ;
}

inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

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

int main()
{
	read(T);
	while (T--)
	{
		read(n);
		bool no = false;
		cnt1 = cnt2 = 0;
		for (int i = 1; i <= n; i++)
		{
			read(p);
			read(q);
			read(r);
			if (!r)
			{
				conflict[++cnt1][0] = p;
				conflict[cnt1][1] = q;
				b[(i << 1) - 1].first = p;
				b[(i << 1) - 1].second = &conflict[cnt1][0];
				b[i << 1].first = q;
				b[i << 1].second = &conflict[cnt1][1];
			}
			else
			{
				same[++cnt2][0] = p;
				same[cnt2][1] = q;
				b[(i << 1) - 1].first = p;
				b[(i << 1) - 1].second = &same[cnt2][0];
				b[i << 1].first = q;
				b[i << 1].second = &same[cnt2][1];
			}
		}
		Discretization();
		for (int i = 1; i <= m; i++) father[i] = i;
		for (int i = 1; i <= cnt2; i++) father[getfather(same[i][0])] = getfather(same[i][1]);
		for (int i = 1; i <= cnt1; i++)
		{
			int x = getfather(conflict[i][0]), y = getfather(conflict[i][1]);
			if (x == y)
			{
				no = true;
				break;
			}
		}
		if (no) puts("NO");
		else puts("YES");
	}
	return 0;
}
