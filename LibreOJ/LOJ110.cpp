#include <cstdio>
#define MAXN 3000010
using namespace std;

int n, MOD;
long long inv[MAXN];

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
	read(MOD);
	inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = (long long)(MOD - MOD / i) * inv[MOD % i] % MOD;
	for (int i = 1; i <= n; i++) printf("%lld\n", inv[i]);
	return 0;
}