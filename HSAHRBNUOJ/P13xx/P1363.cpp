#include <cstdio>
#include <algorithm>
#define MAXN 200100
using namespace std;

int a[MAXN];
int num[MAXN], diff[MAXN];
int n, m;
int cnt, ans;
int now = -1;
int head = 1, tail = 1;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == now) diff[cnt]++;
		else
		{
			cnt++;
			diff[cnt]++;
			num[cnt] = a[i];
			now = a[i];
		}
	}
	while (true)
	{
		if (head > cnt || tail > cnt) break;
		while (num[head] - num[tail] > m) tail++;
		while (num[head] - num[tail] < m) head++;
		if (num[head] - num[tail] == m)
		{
			ans += diff[head] * diff[tail];
			head++;
			tail++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
