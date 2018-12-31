//Code By HeRaNO
#include <stdio.h>
#define MAXN 100010

long long a[MAXN], b[MAXN];
long long cnt;

void Merge(int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j]) b[k++] = a[i++];
		else
		{
			cnt += j - k;
			b[k++] = a[j++];
		}
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= right) b[k++] = a[j++];
	for (int i = left; i <= right; i++) a[i] = b[i];
}

void MergeSort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		Merge(left, mid, right);
	}
}

int main()
{
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", &a[i]);
	MergeSort(0, m - 1);
	printf("%lld\n", cnt);
	return 0;
}
