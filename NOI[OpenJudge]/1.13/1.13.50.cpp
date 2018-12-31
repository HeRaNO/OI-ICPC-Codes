//Code By HeRaNO
#include <stdio.h>
int main()
{
	char str[1001];
	int i, sum;
	gets(str);
	if (str[0] == '0')
	{
		printf("0");
		return 0;
	}
	for (i = 0, sum = 0; str[i] != '\0'; i++)
		sum += str[i] - '0';
	printf("%d\n", (sum - 1) % 9 + 1);
	return 0;
}
