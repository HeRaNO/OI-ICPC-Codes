#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 1000010
using namespace std;

int block_num;
int a[MAXN], b[MAXN], delta[MAXN], pos[MAXN];
int n, m, l, r, x, t;
char opt[5];

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void clean(int x)
{
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) b[i] = a[i];
	sort(b + l, b + r + 1);
}

int binary(int x, int k)
{
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	int last = r, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (b[mid] < k) l = mid + 1;
		else r = mid - 1;
	}
	return last - l + 1;
}

void modify(int left, int right, int k)
{
	if (pos[left] == pos[right])
	{
		for (int i = left; i <= right; i++) a[i] += k;
	}
	else
	{
		for (int i = left; i <= pos[left]*block_num; i++) a[i] += k;
		for (int i = (pos[right] - 1) * block_num + 1; i <= right; i++) a[i] += k;
	}
	clean(pos[left]);
	clean(pos[right]);
	for (int i = pos[left] + 1; i < pos[right]; i++) delta[i] += k;
	return ;
}

int query(int left, int right, int k)
{
	int res = 0;
	if (pos[left] == pos[right])
	{
		for (int i = left; i <= right; i++) if (a[i] + delta[pos[i]] >= k) res++;
	}
	else
	{
		for (int i = left; i <= pos[left]*block_num; i++) if (a[i] + delta[pos[i]] >= k) res++;
		for (int i = (pos[right] - 1) * block_num + 1; i <= right; i++) if (a[i] + delta[pos[i]] >= k) res++;
	}
	for (int i = pos[left] + 1; i < pos[right]; i++) res += binary(i, k - delta[i]);
	return res;
}

int main()
{
	scanf("%d %d", &n, &t);
	block_num = int(sqrt(n));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[i] = (i - 1) / block_num + 1;
		b[i] = a[i];
	}
	if (n % block_num) m = n / block_num + 1;
	else m = n / block_num;
	for (int i = 1; i <= m; i++) clean(i);
	while (t--)
	{
		scanf("%s %d %d %d", opt, &l, &r, &x);
		if (opt[0] == 'M') modify(l, r, x);
		else printf("%d\n", query(l, r, x));
	}
	return 0;
}
