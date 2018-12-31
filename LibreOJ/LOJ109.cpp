#include <cstdio>
#define MAXN 4000010
#define MOD 998244353LL
using namespace std;

int n, T, opt, u, v, father[MAXN];
long long ans;

inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
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
	read(T);
	for (int i = 1; i <= n; i++) father[i] = i;
	while (T--)
	{
		read(opt);
		read(u);
		read(v);
		if (!opt) father[getfather(v)] = getfather(u);
		else ans = ((ans << 1) | (getfather(v) == getfather(u))) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}