#include <cstdio>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct line
{
	double k;
	double b;
	int id;
};

line a[MAXN], sta[MAXN];
int n, top, pos;

bool cmp(line a, line b)
{
	if (a.k == b.k) return a.b < b.b;
	return a.k < b.k;
}

bool cmpid(line a, line b)
{
	return a.id < b.id;
}

bool under(line a, line b)
{
	return a.b <= b.k * a.k + b.b;
}

line intersection(line a, line b)
{
	return (line)
	{
		(b.b - a.b) / (a.k - b.k), (a.k * b.b - b.k * a.b) / (a.k - b.k), 0
	};
}

int main()
{
	//freopen("line.in","r",stdin);freopen("line.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &a[i].k, &a[i].b);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	pos = 1;
	while (pos <= n && a[pos].k == a[pos + 1].k) pos++;
	sta[top++] = a[pos++];
	while (pos <= n)
	{
		while (top > 1 && (a[pos].k == sta[top - 1].k || under(intersection(a[pos], sta[top - 1]), sta[top - 2]))) top--;
		sta[top++] = a[pos++];
	}
	sort(sta, sta + top, cmpid);
	for (int i = 0; i < top; i++) printf("%d ", sta[i].id);
	return 0;
}
