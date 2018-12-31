//Code By HeRaNO
#include <cstdio>
#define MAXN 10010
using namespace std;

int cnt[MAXN];
int fmax, n, a;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		cnt[a]++;
		fmax = mymax(a, fmax);
	}
	for (int i = 0; i <= fmax; i++)
		printf("%d\n", cnt[i]);
	return 0;
}
