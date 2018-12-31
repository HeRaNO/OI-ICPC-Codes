#include <cstdio>
#define MAXN 510
#define MOD 1000000007LL
using namespace std;

long long A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];
int n, p, m;

inline void read(int &x)
{
	x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	x = f ? -x : x;
	return ;
}

inline void read(long long &x)
{
	x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	x = f ? -x : x;
	return ;
}

int main()
{
	read(n);
	read(p);
	read(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			read(A[i][j]);
	for (int i = 0; i < p; i++)
		for (int j = 0; j < m; j++)
			read(B[i][j]);
	for (int k = 0; k < p; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				(C[i][j] += A[i][k] * B[k][j] % MOD) %= MOD;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%lld%c", (C[i][j] + MOD) % MOD, j == m - 1 ? '\n' : ' ');
	return 0;
}