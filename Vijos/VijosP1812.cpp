#include<cstdio>
using namespace std;

int a, c;
bool first = true;

int main()
{
	scanf("%d", &c);
	for (int i = c; ~i; i--)
	{
		scanf("%d", &a);
		if (!a) continue;
		if (!first)
		{
			if (a > 0) putchar('+');
		}
		else first = false;
		if (a == -1) putchar('-');
		else if (a != 1) printf("%d", a);
		if (i > 1) printf("x^%d", i);
		if (i == 1) putchar('x');
		if (i == 0)
		{
			if (a == -1 || a == 1) putchar('1');
		}
	}
	putchar('\n');
	return 0;
}