#include <cstdio>
#define MAXN 100010
using namespace std;

int n;
long long x, y, X, Y;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n * 2; i++)
	{
		scanf("%I64d %I64d", &x, &y);
		X += x;
		Y += y;
	}
	printf("%I64d %I64d\n", X / n, Y / n);
	return 0;
}