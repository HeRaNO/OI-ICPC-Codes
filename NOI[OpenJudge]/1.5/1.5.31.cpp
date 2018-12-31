//Code By HeRaNO
#include <iostream>
#include <cstdio>
#define MAXN 5001
using namespace std;

bool light[MAXN] = {false};
int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (j % i == 0) light[j] = !light[j];
	for (int i = 1; i <= n; i++)
	{
		if (light[i])
		{
			if (i != 1) printf(",");
			printf("%d", i);
		}
	}
	return 0;
}
