#include <cstdio>
#include <cstring>
#define MAXN 2010
using namespace std;

int a, b, T, k;
int C[MAXN][MAXN];
int pre[MAXN][MAXN], ans[MAXN][MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
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

inline void Triangle(int MOD)
{
	for (int i = 0; i < MAXN; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
	return ;
}

inline void get_ans()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 1; j < MAXN; j++)
			pre[i][j] = pre[i][j - 1] + (C[i][j] == 0);
	for (int i = 0; i < MAXN; i++)
		for (int j = 1; j < MAXN; j++)
			ans[j][i] = ans[j - 1][i] + pre[j][i];
	return ;
}

int main()
{
	//freopen("problem.in","r",stdin);freopen("problem.out","w",stdout);
	memset(C, -1, sizeof C);
	read(T);
	read(k);
	Triangle(k);
	get_ans();
	while (T--)
	{
		read(a);
		read(b);
		printf("%d\n", ans[a][mymin(a, b)]);
	}
	return 0;
}
