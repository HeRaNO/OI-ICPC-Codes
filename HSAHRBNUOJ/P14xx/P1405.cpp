#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define MOD 99999997
using namespace std;

struct match
{
	int pt;
	int len;
};

int n;
match a[MAXN], b[MAXN];
int dp[MAXN], bb[MAXN];
int cnt;

void Merge(int a[], int start, int mid, int end)
{
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j])
			bb[k++] = a[i++];
		else
		{
			cnt = (cnt + j - k) % MOD;
			bb[k++] = a[j++];
		}
	}
	while (i <= mid)
		bb[k++] = a[i++];
	while (j <= end)
		bb[k++] = a[j++];
	for (int i = start; i <= end; i++)
		a[i] = bb[i];
}

void MergeSort(int a[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(a, start, mid);
		MergeSort(a, mid + 1, end);
		Merge(a, start, mid, end);
	}
}

bool cmp(match s, match t)
{
	return s.len < t.len;
}

int main()
{
	//freopen("match.in","r",stdin);freopen("match.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].len);
		a[i].pt = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i].len);
		b[i].pt = i;
	}
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		dp[a[i].pt] = b[i].pt;
	/*  for (int i=1;i<=n;i++)
	    for (int j=i+1;j<=n;j++)
	        if (dp[i]>dp[j]) cnt=(cnt+1)%MOD;*/
	MergeSort(dp, 1, n);
	printf("%d\n", cnt);
	return 0;
}
