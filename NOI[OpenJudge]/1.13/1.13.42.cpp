//Code By HeRaNO
#include <cstdio>
#define MAXP 27
#define MAXB 1010
using namespace std;

int n;
int book[MAXP][MAXB];
int maxbook, in, maxpos;
char c;

int main()
{
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		in = 0;
		while (true)
		{
			c = getchar();
			if (c == ' ') break;
			else in = in * 10 + c - '0';
		}
		while (true)
		{
			c = getchar();
			if (c == '\n') break;
			else book[c - 'A'][++book[c - 'A'][0]] = in;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (book[i][0] > maxbook)
		{
			maxbook = book[i][0];
			maxpos = i;
		}
	}
	c = maxpos + 'A';
	putchar(c);
	putchar('\n');
	for (int i = 0; i <= book[maxpos][0]; i++)
		printf("%d\n", book[maxpos][i]);
	return 0;
}
