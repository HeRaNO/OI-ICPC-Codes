#include <cstdio>
int main()
{
	char c = getchar();
	while (c != '#')
	{
		if (c >= 'a' && c <= 'z') c = (c - 'a' + 4) % 26 + 'a';
		if (c >= 'A' && c <= 'Z') c = (c - 'A' + 4) % 26 + 'A';
		putchar(c);
		c = getchar();
	}
	putchar('\n');
	return 0;
}