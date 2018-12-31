//Code By HeRaNO
#include <cstdio>
using namespace std;
int gold, silver, brozen, n;
int a, b, c;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		gold += a;
		silver += b;
		brozen += c;
	}
	printf("%d %d %d %d", gold, silver, brozen, gold + silver + brozen);
	return 0;
}
