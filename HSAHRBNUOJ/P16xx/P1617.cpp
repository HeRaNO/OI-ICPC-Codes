#include <cstdio>
#include <algorithm>
#define MAXN 1000010
using namespace std;

int a[MAXN], n, m;
int head, tail = 1;

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
	freopen("test9.in", "r", stdin);
	freopen("test.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 0; i < m; i++) read(a[i]);
	sort(a, a + m);
	while (true)
	{
		if (head == m) break;
		while (a[tail] == a[tail - 1]) tail++;
		if (tail - head > (m >> 1))
		{
			printf("%d\n", a[head]);
			return 0;
		}
		head = tail++;
	}
	puts("-1");
	return 0;
}