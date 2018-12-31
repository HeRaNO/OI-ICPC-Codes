#include <stdio.h>

int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int y, m, d, T;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &y, &m, &d);
		if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
		{
			for (int i = 1; i < m; i++) d += b[i];
		}
		else
		{
			for (int i = 1; i < m; i++) d += a[i];
		}
		printf("%d\n", d);
	}
	return 0;
}