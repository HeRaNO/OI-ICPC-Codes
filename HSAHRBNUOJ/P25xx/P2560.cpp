#include <cstdio>
#include <algorithm>
#define MAXN 25
using namespace std;

struct allow
{
	int v;
	int b;
};

allow a[MAXN];
int n, c;
int ans, k;
bool flag;

bool cmp(allow a, allow b)
{
	return a.v < b.v;
}

int main()
{
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].v, &a[i].b);
	sort(a + 1, a + n + 1, cmp);
	flag = true;
	while (flag)
	{
		flag = false;
		k = c;
		for (int i = n; i; i--)
			while (a[i].b > 0 && k - a[i].v >= 0)
			{
				k -= a[i].v;
				a[i].b--;
			}
		for (int i = 1; i <= n; i++)
			if (a[i].b > 0 && k > 0)
			{
				k -= a[i].v;
				a[i].b--;
			}
		if (k <= 0)
		{
			ans++;
			flag = true;
		}
	}
	printf("%d\n", ans);
	return 0;
}
