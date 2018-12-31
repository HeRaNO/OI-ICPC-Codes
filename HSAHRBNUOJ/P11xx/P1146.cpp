#include <cstdio>
#include <algorithm>
#define MAXN 5010
using namespace std;

struct Volunteer
{
	int id, x;
};

Volunteer a[MAXN];
int n, m;

bool cmp(Volunteer a, Volunteer b)
{
	return a.x == b.x ? a.id<b.id: a.x>b.x;
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
	read(m);
	m = ((m << 1) + m) >> 1;
	for (int i = 1; i <= n; i++) read(a[i].id), read(a[i].x);
	sort(a + 1, a + n + 1, cmp);
	while (a[m + 1].x == a[m].x) m++;
	printf("%d %d\n", a[m].x, m);
	for (int i = 1; i <= m; i++) printf("%d %d\n", a[i].id, a[i].x);
	return 0;
}