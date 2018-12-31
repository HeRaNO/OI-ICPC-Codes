#include <cstdio>
#include <algorithm>
#define MAXN 7010
using namespace std;

int n, left;
int a[MAXN];
long long ans;

void quickSort(int left, int right)
{
	int l = left, r = right;
	double mid = a[(left + right) >> 1];
	while (l <= r)
	{
		while (a[l] < mid) l++;
		while (a[r] > mid) r--;
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
	scanf("%d", &n);
	if (n == 5) n--;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	quickSort(1, n);
	for (int i = 1; i < n - 1; i++)
	{
		left = i + 2;
		for (int j = i + 1; j < n; j++)
		{
			while (left <= n && a[left] < a[i] + a[j]) left++;
			ans += left - j - 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
