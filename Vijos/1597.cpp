#include <stdio.h>
void print(int n)
{
	int i, k;
	for (k = 0; k <= 15 && (n & (1 << k)) == 0; k++);
	for (i = 15; i > k; i--)
	{
		if (n & (1 << i))
		{
			putchar('2');
			if (i != 1)
			{
				putchar('(');
				print(i);
				putchar(')');
			}
			putchar('+');
		}
	}
	putchar('2');
	if (k != 1)
	{
		putchar('(');
		if (k == 0)
			putchar('0');
		else
			print(k);
		putchar(')');
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	print(num);
	return 0;
}