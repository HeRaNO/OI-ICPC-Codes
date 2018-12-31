//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 510
using namespace std;

int a, n;
int pt[MAXN], cnt;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if (a & 1)  pt[cnt++] = a;
	}
	sort(pt, pt + cnt);
	for (int i = 0; i < cnt - 1; i++)
		printf("%d,", pt[i]);
	printf("%d\n", pt[cnt - 1]);
	return 0;
}
