#include <cstdio>
#define MAXN 310
#define MAXC 10000010
using namespace std;

int n, a, b, c, d, ans;
int father[MAXC];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

int main()
{
	for (int i = 0; i < MAXC; i++) father[i] = i;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		a = getfather(a);
		b = getfather(b);
		if (a != b)
		{
			father[b] = a;
			ans++;
		}
		c = getfather(c);
		d = getfather(d);
		if (c != d)
		{
			father[d] = c;
			ans++;
		}
	}
	printf("%d\n", mymin(ans, n));
	return 0;
}
