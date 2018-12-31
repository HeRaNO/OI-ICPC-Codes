//Code By HeRaNO
#include <stdio.h>
#include <string.h>
int main()
{
	int n, i;
	char a[45] = {'\0'}, b[85] = {'\0'};
	int lenA = 0, lenB = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", a);
		lenA = strlen(a);
		if (lenB + 1 + lenA < 79)
		{
			if (lenB > 0) strcat(b, " ");
			strcat(b, a);
			lenB = strlen(b);
		}
		else if (lenB + 1 + lenA == 80 || lenB + 1 + lenA == 79)
		{
			printf("%s %s\n", b, a);
			lenB = 0;
			b[0] = '\0';
		}
		else
		{
			printf("%s\n", b);
			strcpy(b, a);
			lenB = strlen(b);
		}
	}
	printf("%s\n", b);
	return 0;
}
