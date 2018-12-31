//Code By HeRaNO
#include <cstdio>
using namespace std;
int sum, m, ans, a;
int main()
{
	scanf("%d", &sum);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a);
		if (sum < a) ans++;
		else sum -= a;
	}
	printf("%d", ans);
}
