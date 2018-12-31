#include <cstdio>
#include <climits>
#include <algorithm>
#define MAXN 100010
#define UP 0
#define LE 1
#define DN 2
#define RI 3
using namespace std;

const long long dx[4] = {0, -1, 0, 1};
const long long dy[4] = {1, 0, -1, 0};

struct mir
{
	long long x;
	long long y;
	long long status;
};

mir xm[MAXN], ym[MAXN];
int n, m;
char s[3];
long long t, tt;
long long nowx = 0, nowy = 0;
int nowsta = RI;

long long myabs(long long a)
{
	return a < 0 ? -a : a;
}

bool cmpx(mir a, mir b)
{
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool cmpy(mir a, mir b)
{
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

bool operator == (const mir &a, const mir &b)
{
	return a.x == b.x && a.y == b.y;
}

mir *binary_x_more(mir a)
{
	int left = 0, right = n + 1;
	while (left < right)
	{
		int middle = (left + right) >> 1;
		if (xm[middle] == a) return xm + middle;
		else if (cmpx(a, xm[middle])) right = middle;
		else left = middle + 1;
	}
	if (left < 1 || left > n || a.x != xm[left].x) return NULL;
	return xm + left;
}

mir *binary_y_more(mir a)
{
	int left = 0, right = n + 1;
	while (left < right)
	{
		int middle = (left + right) >> 1;
		if (ym[middle] == a) return ym + middle;
		else if (cmpy(a, ym[middle])) right = middle;
		else left = middle + 1;
	}
	if (left < 1 || left > n || a.y != ym[left].y) return NULL;
	return ym + left;
}

mir *binary_x_less(mir a)
{
	int left = 0, right = n + 1;
	while (left < right)
	{
		int middle = ((left + right) >> 1) + 1;
		if (xm[middle] == a) return xm + middle;
		else if (cmpx(xm[middle], a)) left = middle;
		else right = middle - 1;
	}
	if (left < 1 || left > n || a.x != xm[left].x) return NULL;
	return xm + left;
}

mir *binary_y_less(mir a)
{
	int left = 0, right = n + 1;
	while (left < right)
	{
		int middle = ((left + right) >> 1) + 1;
		if (ym[middle] == a) return ym + middle;
		else if (cmpy(ym[middle], a)) left = middle;
		else right = middle - 1;
	}
	if (left < 1 || left > n || a.y != ym[left].y) return NULL;
	return ym + left;
}

int main()
{
	scanf("%lld %lld %lld", &n, &m, &t);
	tt = t;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld %lld %s", &xm[i].x, &xm[i].y, s);
		ym[i].x = xm[i].x;
		ym[i].y = xm[i].y;
		if (s[0] == '/')
		{
			xm[i].status = RI;
			ym[i].status = LE;
		}
		else
		{
			xm[i].status = LE;
			ym[i].status = RI;
		}
	}
	xm[0] = (mir)
	{
		INT_MIN, INT_MIN, 0
	};
	xm[n + 1] = (mir)
	{
		INT_MAX, INT_MAX, 0
	};
	ym[0] = (mir)
	{
		INT_MIN, INT_MIN, 0
	};
	ym[n + 1] = (mir)
	{
		INT_MAX, INT_MAX, 0
	};
	sort(xm + 1, xm + n + 1, cmpx);
	sort(ym + 1, ym + n + 1, cmpy);
	while (true)
	{
		mir *res;
		if (nowsta == UP) res = binary_x_more((mir)
		{
			nowx, nowy + 1
		});
		else if (nowsta == LE) res = binary_y_less((mir)
		{
			nowx - 1, nowy
		});
		else if (nowsta == DN) res = binary_x_less((mir)
		{
			nowx, nowy - 1
		});
		else res = binary_y_more((mir)
		{
			nowx + 1, nowy
		});
		if (res)
		{
			if (nowy == 0 && res->y == 0 && nowx < 0 && res->x > 0) t %= (tt - t - nowx);
			long long dis = myabs(res->x - nowx) + myabs(res->y - nowy);
			if (dis < t)
			{
				nowx = res->x;
				nowy = res->y;
				nowsta = (nowsta + res->status) % 4;
				t -= dis;
			}
			else
			{
				printf("%lld %lld\n", nowx + t * dx[nowsta], nowy + t * dy[nowsta]);
				return 0;
			}
		}
		else
		{
			printf("%lld %lld\n", nowx + t * dx[nowsta], nowy + t * dy[nowsta]);
			return 0;
		}
	}
	return 0;
}
