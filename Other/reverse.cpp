#include <ctime>
#include <cstdio>
#define MAXN 1000010
using namespace std;

bool a[MAXN], c[MAXN], m;
int n, T, l, r, x;

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
	clock_t st, ed;
	freopen("data.txt", "r", stdin);
	freopen("ans.txt", "w", stdout);
	st = clock();
	read(n);
	read(T);
	for (int i = 1; i <= n; i++) read(x), a[i] = x;
	a[0] = a[n];
	m = a[1];
	for (int i = 1; i <= n; i++) c[i] = a[i] ^ a[i - 1];
	while (T--)
	{
		read(l);
		read(r);
		r++;
		c[l] = !c[l];
		c[r] = !c[r];
		if (l <= r && 1 == l) m = !m;
		else if (l >= r) m = !m;
	}
	printf("%d", m);
	for (int i = 2; i <= n; i++) printf(" %d", m = c[i] ? !m : m);
	puts("");
	ed = clock();
	printf("%lf\n", (double)(ed - st) / CLOCKS_PER_SEC);
	return 0;
}
