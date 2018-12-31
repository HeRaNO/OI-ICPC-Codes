#include <cstdio>
#include <algorithm>
#define MAXN 1000010
#define L first
#define R second
using namespace std;

int n, ans;
pair <int, int> a[MAXN];
int q[MAXN], head = 1, tail;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
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
	for (int i = 1; i <= n; i++) read(a[i].L), read(a[i].R);
	for (int i = 1; i <= n; i++)
	{
		while (head <= tail && a[i].L >= a[q[tail]].L) q[tail--] = 0;
		q[++tail] = i;
		while (head <= tail && a[i].R < a[q[head]].L) head++;
		ans = mymax(ans, q[tail] - q[head - 1]);
	}
	printf("%d\n", ans);
	return 0;
}
