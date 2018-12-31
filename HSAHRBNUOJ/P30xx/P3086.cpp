#include <math.h>
#include <stdio.h>

int x, T;

__attribute__((__optimize__("-O2"))) inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

__attribute__((__optimize__("-O2"))) inline void print(int x)
{
	if (x < 10)
	{
		putchar(x + '0');
		return ;
	}
	print(x / 10);
	putchar(x % 10 + '0');
	return ;
}

__attribute__((__optimize__("-O2"))) int main()
{
	read(T);
	while (T--)
	{
		read(x);
		print(sqrt(x) + 0.5);
		putchar('\n');
	}
	return 0;
}