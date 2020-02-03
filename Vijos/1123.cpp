#include<cstdio>
using namespace std;
const int MAXN = 100 + 10;

int num[MAXN];

int main()
{
	int n, ans = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
	}
	sum /= n;
	for (int i = 1; i < n; i++)
		if (num[i] != sum)
		{
			num[i + 1] -= sum - num[i];
			ans++;
		}
	printf("%d", ans);
	return 0;
}
