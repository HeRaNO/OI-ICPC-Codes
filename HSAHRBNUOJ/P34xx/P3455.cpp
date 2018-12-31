#include <cstdio>
#define MAXN 1000010
using namespace std;

struct link
{
	int from;
	int to;
};

link e[MAXN];
int n, m, pt = 1;
int degree[MAXN];
long long ans[MAXN], res, nn;

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
	//freopen("triangle.in","r",stdin);freopen("triangle.out","w",stdout);
	read(n);
	read(m);
	nn = n;
	for (int i = 1; i <= m; i++)
	{
		read(e[i].from);
		read(e[i].to);
		degree[e[i].from]++;
		degree[e[i].to]++;
	}
	for (int i = 1; i <= m; i++)
	{
		ans[e[i].from] += 2 * degree[e[i].to] + 1 - n;
		ans[e[i].to] += 2 * degree[e[i].from] + 1 - n;
	}
	for (int i = 1; i <= n; i++) ans[i] -= degree[i] * (n - degree[i] - 2);
	for (int i = 1; i <= n; i++) res += degree[i] * (n - degree[i] - 2);
	for (int i = 1; i <= n; i++) if (ans[i] > ans[pt]) pt = i;
	res = (nn - 1LL) * (nn - 2LL) * (nn - 3LL) / 6LL - (res + ans[pt]) / 2LL;
	printf("%d %lld\n", pt, res, ans[0]);
	return 0;
}
