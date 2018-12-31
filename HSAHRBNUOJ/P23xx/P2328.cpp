#include <cstdio>
using namespace std;
int p[8] = {0, 1, 2, 6, 24, 120, 720, 5040};
int n, i, pp;
int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &pp);
		printf("%d\n", p[pp]);
	}
	return 0;
}
