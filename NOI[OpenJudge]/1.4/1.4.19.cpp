//Code By HeRaNO
#include <stdio.h>
int main()
{
	int a, b;
	char c;
	scanf("%d%d %c", &a, &b, &c);
	if (c == '/' && b == 0)
	{
		printf("Divided by zero!");
		return 0;
	}
	else if (c != '+' && c != '-' && c != '*' && c != '/')
	{
		printf("Invalid operator!");
		return 0;
	}
	if (c == '+') printf("%d", a + b);
	else if (c == '-') printf("%d", a - b);
	else if (c == '*') printf("%d", a * b);
	else if (c == '/') printf("%d", a / b);
	return 0;
}