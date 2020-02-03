#include<cstdio>
#include<algorithm>
using namespace std;
struct Type
{
	int x, y;
} a[50001];
int n, l, r;
bool my_comp(const Type &a, const Type &b)
{
	if (a.x < b.x) return 1;
	if (a.x > b.x) return 0;
	if (a.y < b.y) return 1;
	return 0;
}
int main()
{
	//freopen("p1.in","r",stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	sort(a + 1, a + n + 1, my_comp);
	l = a[1].x;
	r = a[1].y;
	for (int i = 2; i <= n; i++)
		if (a[i].x > r)
		{
			printf("%d %d\n", l, r);
			l = a[i].x;
			r = a[i].y;
			continue;
		}
		else r = max(r, a[i].y);
	printf("%d %d", l, r);
	return 0;
}
