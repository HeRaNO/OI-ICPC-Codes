#include <stdio.h>

inline int GPA(int x)
{
	if (x >= 90) return 4;
	if (x >= 80) return 3;
	if (x >= 70) return 2;
	if (x >= 60) return 1;
	return 0;
}

int n, a, b, p, q;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		p += a * GPA(b);
		q += a;
	}
	printf("%.2lf\n", (double)p / (double)q);
	return 0;
}