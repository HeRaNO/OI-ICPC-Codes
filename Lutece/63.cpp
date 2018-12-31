#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if (n == 1) ++n;
	for (int i = 1; i <= (n >> 1); i++) printf("Wed.Strong");
	puts("");
	return 0;
}
