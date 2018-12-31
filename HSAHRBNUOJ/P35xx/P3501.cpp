#include <cstdio>
using namespace std;

int n, k;
int cnt = 2;

int main()
{
	scanf("%d %d", &n, &k);
	if ((k == 1 && n != 1) || (n < k))
	{
		puts("-1");
		return 0;
	}
	else if (k == 1 && n == 1)
	{
		puts("a");
		return 0;
	}
	for (int i = 1; i <= n - k + 2; i++)
		if (i & 1) putchar('a');
		else putchar('b');
	for (int i = n - k + 3; i <= n; i++, cnt++) putchar(cnt + 'a');
	putchar('\n');
	return 0;
}
