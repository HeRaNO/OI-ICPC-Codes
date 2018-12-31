#include <cstdio>
#define MAXN 1000010
using namespace std;

int a[MAXN], b[MAXN];
int q[MAXN];
int head = 1, tail = 1, r = 2;
int ans, n;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	//freopen("sequence.in","r",stdin);freopen("sequence.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &a[i], &b[i]);
	q[1] = 1;
	for (int l = 1; l <= n && r <= n; l++)
	{
		while (head <= tail && q[head] < l) head++;
		if (r <= l) r = l + 1, q[++tail] = l;
		while (r <= n && b[r] >= a[q[head]])
		{
			while (head <= tail && a[q[tail]] < a[r]) tail--;
			q[++tail] = r++;
		}
		ans = mymax(ans, r - l);
	}
	printf("%d\n", ans);
	return 0;
}
