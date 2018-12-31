//Code By HeRaNO
#include <cstdio>
#define MAXN 110
using namespace std;

int a[MAXN][MAXN];
int n;

void del(int n, int num, bool x)
{
	bool key = 1;
	if (x)
	{
		if (key)
		{
			int bestmin = a[num][0];
			for (int i = 1; i < n; i++)
				if (bestmin > a[num][i]) bestmin = a[num][i];
			for (int i = 0; i < n; i++)a[num][i] -= bestmin;
		}
		else del(n, num, 1);
	}
	else
	{
		if (key)
		{
			int bestmin = a[0][num];
			for (int i = 1; i < n; i++)
				if (bestmin > a[i][num]) bestmin = a[i][num];
			for (int i = 0; i < n; i++)a[i][num] -= bestmin;
		}
		else del(n, num, 0);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	while (n)
	{
		printf("%d\n", a[1][1]);
		for (int i = 0; i < n; i++) del(n, i, 1);
		for (int i = 0; i < n; i++) del(n, i, 0);
		for (int i = 0; i < n; i++)
			for (int j = 1; j < n - 1; j++)
				a[i][j] = a[i][j + 1];
		for (int i = 0; i < n; i++)
			for (int j = 1; j < n - 1; j++)
				a[j][i] = a[j + 1][i];
		n--;
	}
	return 0;
}
