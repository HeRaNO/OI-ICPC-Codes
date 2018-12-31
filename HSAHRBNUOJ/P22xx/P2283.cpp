#include <cstdio>
#define MAXN 105
using namespace std;

int n, S, L[MAXN], R[MAXN], p[MAXN], q[MAXN];
bool f[MAXN];

inline int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

inline int dfs(int x)
{
	if (!x) return 1;
	int lc = dfs(L[x]), rc = dfs(R[x]);
	int g = gcd(lc * p[x], rc * q[x]);
	return lc * (rc * q[x] / g) + rc * (lc * p[x] / g);
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(p[i]);
		read(q[i]);
		read(L[i]);
		read(R[i]);
		f[L[i]] = f[R[i]] = true;
	}
	for (int i = 1; i <= n; i++) if (!f[i])
		{
			S = i;
			break;
		}
	printf("%d\n", dfs(S));
	return 0;
}