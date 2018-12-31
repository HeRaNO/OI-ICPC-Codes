#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 10010
#define MAXC 1000010
using namespace std;

int n, m, T, block_num, x, y;
int a[MAXN], b[MAXN], c[MAXN];
int pos[MAXN], last[MAXC];
char opt[3];

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void clean(int x)
{
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) a[i] = b[i];
	sort(a + l, a + r + 1);
}

int binary(int x, int v)
{
	int left = (x - 1) * block_num + 1, right = mymin(x * block_num, n);
	int first = left, middle;
	while (left <= right)
	{
		middle = (left + right) >> 1;
		if (a[middle] < v) left = middle + 1;
		else right = middle - 1;
	}
	return left - first;
}

int query(int left, int right)
{
	int ans = 0;
	if (pos[left] == pos[right])
	{
		for (int i = left; i <= right; i++) if (b[i] < left) ans++;
	}
	else
	{
		for (int i = left; i <= block_num * pos[left]; i++) if (b[i] < left) ans++;
		for (int i = (pos[right] - 1) * block_num + 1; i <= right; i++) if (b[i] < left) ans++;
	}
	for (int i = pos[left] + 1; i < pos[right]; i++) ans += binary(i, left);
	return ans;
}

void modify(int x, int v)
{
	for (int i = 1; i <= n; i++) last[c[i]] = 0;
	c[x] = v;
	for (int i = 1; i <= n; i++)
	{
		int t = b[i];
		b[i] = last[c[i]];
		if (b[i] != t) clean(pos[i]);
		last[c[i]] = i;
	}
	return ;
}

int main()
{
	scanf("%d %d", &n, &T);
	block_num = (int)sqrt(n);
	if (n % block_num) m = n / block_num + 1;
	else m = n / block_num;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		b[i] = last[c[i]];
		last[c[i]] = i;
		pos[i] = (i - 1) / block_num + 1;
	}
	for (int i = 1; i <= m; i++) clean(i);
	while (T--)
	{
		scanf("%s %d %d", opt, &x, &y);
		if (opt[0] == 'Q') printf("%d\n", query(x, y));
		else modify(x, y);
	}
	return 0;
}