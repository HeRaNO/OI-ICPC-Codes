#include <stdio.h>
#include <string.h>

int T, n, pt;
char s[200];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		pt = 0;
		n = strlen(s);
		while (pt < n)
		{
			if (s[pt] >= '0' && s[pt] <= '9')
			{
				int x = 0;
				while (pt < n && s[pt] >= '0' && s[pt] <= '9') x = (x << 3) + (x << 1) + s[pt++] - '0';
				printf("%d ", x);
			}
			else ++pt;
		}
		putchar('\n');
	}
	return 0;
}