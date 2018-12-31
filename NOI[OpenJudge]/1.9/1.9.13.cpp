//Code By HeRaNO
#include <cstdio>
#define MAXN 101
using namespace std;

bool c[MAXN] = {false};
int a, n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if (!c[a]) printf("%d ", a);
		c[a] = true;
	}
	return 0;
}
