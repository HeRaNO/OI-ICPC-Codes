#include <stdio.h>

int a, b, c, p[11][11], q[11][11], r[11][11];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &a, &b, &c);
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++)
				scanf("%d", &p[i][j]);
		for (int i = 1; i <= b; i++)
			for (int j = 1; j <= c; j++)
				scanf("%d", &q[i][j]);
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= c; j++)
			{
				r[i][j] = 0;
				for (int k = 1; k <= b; k++)
					r[i][j] += p[i][k] * q[k][j];
			}
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= c; j++)
				printf("%d%c", r[i][j], j == c ? '\n' : ' ');
		putchar('\n');
	}
	return 0;
}