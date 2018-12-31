#include <cmath>
#include <cstdio>
#define MAXN 100010
using namespace std;

int n, ans, lim, x, y;
int L[MAXN], R[MAXN];
bool flag;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

void dfs(int x, int dep, int &mx, int &mn)
{
	if (dep > lim)
	{
		flag = true;
		return ;
	}
	int lmn = 0, lmx = n;
	if (~L[x]) dfs(L[x], dep + 1, lmx, lmn);
	else lmn = lmx = dep;
	int rmn = 0, rmx = n;
	if (~R[x]) dfs(R[x], dep + 1, rmx, rmn);
	else rmn = rmx = dep;
	if (flag) return ;
	if (lmx != lmn && rmx != rmn)
	{
		flag = true;
		return ;
	}
	mx = mymax(lmx, rmx);
	mn = mymin(lmn, rmn);
	if (mx - mn > 1)
	{
		flag = true;
		return ;
	}
	if (lmn < rmx) ans++;
	return ;
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
	read(n);
	lim = log2(n) + 2;
	for (int i = 1; i <= n; i++) read(L[i]), read(R[i]);
	dfs(1, 0, x, y);
	if (x - y > 1) flag = true;
	printf("%d\n", flag ? -1 : ans);
	return 0;
}
