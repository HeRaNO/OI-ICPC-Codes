//Code By HeRaNO
#include <cstdio>
#define MAXN 101
using namespace std;

int cnt[MAXN];
int n, a;
double s;

int main()
{
	scanf("%d", &n);
	s = n / 2.0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		cnt[a + 49]++;
	}
	for (int i = 0; i < 100; i++)
		if (cnt[i] > s)
		{
			printf("%d\n", i - 49);
			return 0;
		}
	printf("no\n");
	return 0;
}
