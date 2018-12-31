#include <cstdio>
#include <cstring>
#define MAXN 110
using namespace std;

char a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int len[4];
bool yes;

int main()
{
	scanf("%s", a);
	scanf("%s", b);
	scanf("%s", c);
	scanf("%s", d);
	len[0] = strlen(a);
	len[1] = strlen(b);
	len[2] = strlen(c);
	len[3] = strlen(d);
	if (len[0] * 2 <= len[1] && len[0] * 2 <= len[2] && len[0] * 2 <= len[3])
	{
		putchar('A');
		putchar('\n');
		return 0;
	}
	if (len[1] * 2 <= len[0] && len[1] * 2 <= len[2] && len[1] * 2 <= len[3])
	{
		putchar('B');
		putchar('\n');
		return 0;
	}
	if (len[2] * 2 <= len[0] && len[2] * 2 <= len[1] && len[2] * 2 <= len[3])
	{
		putchar('C');
		putchar('\n');
		return 0;
	}
	if (len[3] * 2 <= len[0] && len[3] * 2 <= len[1] && len[0] * 2 <= len[2])
	{
		putchar('D');
		putchar('\n');
		return 0;
	}
	if (len[0] >= len[1] * 2 && len[0] >= len[2] * 2 && len[0] >= len[3] * 2)
	{
		putchar('A');
		putchar('\n');
		return 0;
	}
	if (len[1] >= len[0] * 2 && len[1] >= len[2] * 2 && len[1] >= len[3] * 2)
	{
		putchar('B');
		putchar('\n');
		return 0;
	}
	if (len[2] >= len[0] * 2 && len[2] >= len[1] * 2 && len[2] >= len[3] * 2)
	{
		putchar('C');
		putchar('\n');
		return 0;
	}
	if (len[3] >= len[0] * 2 && len[3] >= len[1] * 2 && len[3] >= len[2] * 2)
	{
		putchar('D');
		putchar('\n');
		return 0;
	}
	if (len[0] > len[1] && len[0] > len[3] && len[2] > len[1] && len[2] > len[3])
	{
		putchar('B');
		putchar('\n');
		return 0;
	}
	if (len[1] > len[0] && len[1] > len[2] && len[3] > len[0] && len[3] > len[2])
	{
		putchar('B');
		putchar('\n');
		return 0;
	}
	for (int i = 0; i < 4 && !yes; i++)
		for (int j = 0; j < 4 && !yes; j++)
			for (int k = 0; k < 4 && !yes; k++)
				for (int l = 0; l < 4 && !yes; l++)
				{
					if (i == j || i == k || i == l || j == k || j == l || k == l) continue;
					if (len[i] > 2 * len[k] && len[j] > 2 * len[l]) yes = true;
				}
	if (yes)
	{
		putchar('D');
		putchar('\n');
		return 0;
	}
	putchar('C');
	putchar('\n');
	return 0;
}
