#include <cstdio>
#define MAXN 100010
using namespace std;

int n, a[MAXN], b[MAXN];
long long cnt;

void Merge(int left, int middle, int right)
{
	int i = left, j = middle + 1, k = left;
	while (i <= middle && j <= right)
	{
		if (a[i] <= a[j]) b[k++] = a[i++];
		else
		{
			cnt += j - k;
			b[k++] = a[j++];
		}
	}
	while (i <= middle) b[k++] = a[i++];
	while (j <= right) b[k++] = a[j++];
	for (int i = left; i <= right; i++) a[i] = b[i];
	return ;
}

void MergeSort(int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) >> 1;
		MergeSort(left, middle);
		MergeSort(middle + 1, right);
		Merge(left, middle, right);
	}
	return ;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	MergeSort(1, n);
	printf("%lld\n", cnt);
	return 0;
}
