#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 600010
using namespace std;

struct link
{
	int from;
	int to;
	double len;
};

link a[4 * MAXN];
int father[4 * MAXN];
int n, m, cnt, dis;
int tmpx1, tmpx2;
double x1, x2;
double y11[MAXN], y2[MAXN];
double ans;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

inline double get_dis(double x1, double x2, double y11, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y11 - y2) * (y11 - y2));
}

bool cmp(link a, link b)
{
	return a.len < b.len;
}

void quickSort(int left, int right)
{
	int l = left, r = right;
	double mid = a[(left + right) / 2].len;
	while (l <= r)
	{
		while (a[l].len < mid) l++;
		while (a[r].len > mid) r--;
		if (l <= r)
		{
			swap(a[l], a[r]);
			l++, r--;
		}
	}
	if (left < r) quickSort(left, r);
	if (l < right) quickSort(l, right);
}

int main()
{
	n = read();
	m = read();
	tmpx1 = read();
	tmpx2 = read();
	x1 = double(tmpx1);
	x2 = double(tmpx2);
	for (int i = 1; i <= n; i++)
	{
		dis = read();
		if (i > 1) a[++cnt] = (link)
		{
			i, i - 1, double(dis)
		};
		y11[i] = y11[i - 1] + double(dis);
	}
	for (int i = 1; i <= m; i++)
	{
		dis = read();
		if (i > 1) a[++cnt] = (link)
		{
			i + n, i + n - 1, double(dis)
		};
		y2[i] = y2[i - 1] + double(dis);
	}
	int j = 1;
	for (int i = 1; i <= n; i++)
	{
		while (j < m && y2[j + 1] < y11[i]) j++;
		a[++cnt] = (link)
		{
			i, j + n, get_dis(x1, x2, y11[i], y2[j])
		};
		if (i == n || y2[j + 1] <= y11[i + 1])
		{
			j++;
			a[++cnt] = (link)
			{
				i, j + n, get_dis(x1, x2, y11[i], y2[j])
			};
			j--;
		}
	}
	//sort(a+1,a+cnt+1,cmp);
	quickSort(1, cnt);
	for (int i = 1; i <= n + m; i++) father[i] = i;
	int sum = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (getfather(a[i].from) != getfather(a[i].to))
		{
			father[getfather(a[i].from)] = getfather(a[i].to);
			ans += a[i].len;
			sum++;
		}
		if (sum == n + m - 1) break;
	}
	printf("%.2lf\n", ans);
	return 0;
}
