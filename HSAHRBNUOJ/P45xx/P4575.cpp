#include <cstdio>
#define MAXN 1000010
using namespace std;

int n, m, l, r, cnt, a[MAXN], ans = ~(1 << 31), appear[MAXN];

inline void min(int &a, int b)
{
	if (a > b) a = b;
	return ;
}

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
	read(n);
	read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	l = 1;
	r = 2;
	appear[a[1]] = 1;
	cnt = 1;
	while (r <= n)
	{
		if (!appear[a[r]]) cnt++;
		appear[a[r]]++;
		while (appear[a[l]] > 1) --appear[a[l++]];
		if (cnt == m) min(ans, r - l + 1);
		r++;
	}
	printf("%d\n", ans);
	return 0;
}