#include <stdio.h>
int main()
{
	int m, i, rest = 0, mum = 0, val = 1;
	for (i = 1; i <= 12; i++)
	{
		rest += 300;
		scanf("%d", &m);
		rest -= m;
		if (rest < 0)
		{
			printf("%d", -i);
			val = 0;
			break;
		}
		else
		{
			int t = (rest / 100) * 100;
			mum += t;
			rest -= t;
		}
	}
	if (val == 1)
		printf("%g", 1.2 * mum + rest);
	return 0;
}
