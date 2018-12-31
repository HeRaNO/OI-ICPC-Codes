//Code By HeRaNO
#include <cstdio>
#define MAXN 10010
using namespace std;

struct rectangle
{
	long long left_x;
	long long left_y;
	long long w;
	long long h;
	long long area;
};

rectangle a[MAXN];
int n;
long long R;
long long left, right, middle;
long long tR;

long long get_difference(long long x)
{
	long long left_size = 0, right_size = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].left_x + a[i].w <= x) left_size += a[i].area;
		else if (a[i].left_x >= x) right_size += a[i].area;
		else
		{
			left_size += (x - a[i].left_x) * a[i].h;
			right_size += (a[i].left_x + a[i].w - x) * a[i].h;
		}
	}
	return right_size - left_size;
}

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%lld", &R);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld %lld %lld %lld", &a[i].left_x, &a[i].left_y, &a[i].w, &a[i].h);
		a[i].area = a[i].w * a[i].h;
		tR = mymax(tR, a[i].left_x + a[i].w);
	}
	left = 0;
	right = R;
	while (left <= right)
	{
		middle = (left + right) >> 1;
		long long res = get_difference(middle);
		if (!res) break;
		else if (res > 0) left = middle + 1;
		else right = middle - 1;
	}
	while (get_difference(middle - 1) <= 0 && middle >= 1) middle--;
	while (get_difference(middle) > 0 && middle < tR) middle++;
	while (get_difference(middle) == get_difference(middle + 1) && middle < R) middle++;
	printf("%lld\n", middle);
	return 0;
}
