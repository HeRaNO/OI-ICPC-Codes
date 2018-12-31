#include <cstdio>
#define MAXN 1000010

int a[MAXN], b[MAXN];
int n;
long long cnt;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

void Merge(int l, int mid, int r)
{
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j]) b[k++] = a[i++];
		else
		{
			cnt += j - k;
			b[k++] = a[j++];
		}
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= r) b[k++] = a[j++];
	for (int i = l; i <= r; i++) a[i] = b[i];
	return ;
}

void MergeSort(int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) >> 1;
		MergeSort(l, mid);
		MergeSort(mid + 1, r);
		Merge(l, mid, r);
	}
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	MergeSort(1, n);
	printf("%lld\n", cnt);
	return 0;
}
