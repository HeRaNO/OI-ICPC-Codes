#include <cstdio>
#define MAXN 100010
using namespace std;

int sta[MAXN], ans, top;
int n, x;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		while (sta[top] > x && top) top--;
		if (sta[top] != x)
		{
			sta[++top] = x;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
