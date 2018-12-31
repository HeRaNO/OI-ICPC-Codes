//Code By HeRaNO
#include <cstdio>
using namespace std;

int n;
int best;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int a1 = 1; a1 <= n; a1++)
		for (int a2 = 1; a2 <= n; a2++)
			for (int a3 = 1; a3 <= n; a3++)
			{
				if ((a1 + a2) % 2 == 0 && (a2 + a3) % 3 == 0 && (a1 + a2 + a3) % 5 == 0)
					best = mymax(best, a1 + a2 + a3);
			}
	printf("%d\n", best);
	return 0;
}
