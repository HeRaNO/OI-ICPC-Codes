#include <stdio.h>

int main()
{
	//1 2 0 2 2 1 0 1
	int n;
	while (~scanf("%d", &n))
	{
		if (n % 8 == 2 || n % 8 == 6) puts("yes");
		else puts("no");
	}
	return 0;
}