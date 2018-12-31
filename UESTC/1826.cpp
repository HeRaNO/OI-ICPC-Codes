#include <stdio.h>
#include <stdlib.h>

int main()
{
	int r, g;
	scanf("%d %d", &r, &g);
	if (!r)
	{
		if (g == 1) puts("YES");
		else puts("NO");
		return 0;
	}
	if (!g)
	{
		if (r == 1) puts("YES");
		else puts("NO");
		return 0;
	}
	if (abs(r - g) <= 1) puts("YES");
	else puts("NO");
	return 0;
}