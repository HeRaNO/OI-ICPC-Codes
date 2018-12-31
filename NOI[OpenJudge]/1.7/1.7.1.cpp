//Code By HeRaNO
#include<stdio.h>
#include<string.h>
int main()
{
	char st[256];
	gets(st);
	int i, a = strlen(st), ans = 0;
	for (i = 0; i <= a; i++)
		if ((st[i] >= '0') && (st[i] <= '9')) ans++;
	printf("%d", ans);
}

