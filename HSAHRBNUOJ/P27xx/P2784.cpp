#include <cstdio>
#define MAXN 210
using namespace std;

struct rectangle
{
	long long x1, x2, y1, y2;
};

rectangle a[MAXN];
int n;
long long ans;

inline void Float(long long x1, long long y1, long long x2, long long y2, int t)
{
	if (x1 >= x2 || y1 >= y2) return ;
	while (t && (x1 >= a[t].x2 || x2 <= a[t].x1 || y1 >= a[t].y2 || y2 <= a[t].y1)) t--;
	if (!t)
	{
		ans += (x2 - x1) * (y2 - y1);
		return ;
	}
	if (x1 < a[t].x1)
	{
		Float(x1, y1, a[t].x1, y2, t);
		x1 = a[t].x1;
	}
	if (x2 > a[t].x2)
	{
		Float(a[t].x2, y1, x2, y2, t);
		x2 = a[t].x2;
	}
	if (y1 < a[t].y1)
	{
		Float(x1, y1, x2, a[t].y1, t);
		y1 = a[t].y1;
	}
	if (y2 > a[t].y2)
	{
		Float(x1, a[t].y2, x2, y2, t);
		y2 = a[t].y2;
	}
	return ;
}

int main()
{
	//freopen("olddriver.in","r",stdin);freopen("olddriver.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld %lld %lld %lld", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
	for (int i = 1; i <= n; i++) Float(a[i].x1, a[i].y1, a[i].x2, a[i].y2, i - 1);
	printf("%lld\n", ans);
	return 0;
}
