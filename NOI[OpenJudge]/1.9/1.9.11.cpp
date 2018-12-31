//Code By HeRaNO
#include<stdio.h>
#include<string.h>
int main()
{
	char c[1001];
	int i, k, l, a;
	scanf("%d\n", &k);
	gets(c);
	l = strlen(c);
	a = 1;
	if (l == 1 && k == 1)
	{
		printf("%c", c[0]);
		return 0;
	}
	else if (l == 1 && k > 1)
	{
		printf("No");
		return 0;
	}
	for (i = 0; i <= l - 2; i++)
	{
		if (c[i + 1] == c[i]) a++;
		else if (a >= k)
		{
			printf("%c", c[i]);
			return 0;
		}
		else a = 1;
	}
	if (a >= k) printf("%c", c[l - 1]);
	else printf("No");
	return 0;
}
