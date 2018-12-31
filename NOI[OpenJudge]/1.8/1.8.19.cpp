//Code By HeRaNO
#include <cstdio>
#define MAXN 1010
using namespace std;

bool a[MAXN][MAXN] = {false};
int n, in;
int s, c;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &in);
			if (in <= 50)
			{
				a[i][j] = true;
				s++;
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if ((!a[i + 1][j] || !a[i][j + 1] || !a[i - 1][j] || !a[i][j - 1]) && a[i][j])
				c++;
	printf("%d %d\n", s, c);
	return 0;
}
