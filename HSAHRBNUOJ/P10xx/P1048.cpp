#include <cstdio>
#define MAXN 10

int n;
char a[1 << MAXN];

inline int FBI(int l, int r)
{
	if (l + 1 == r)
	{
		if (a[l] == '0')
		{
			putchar('B');
			return 0;
		}
		else
		{
			putchar('I');
			return 1;
		}
	}
	int mid = l + r >> 1, lch, rch;
	lch = FBI(l, mid);
	rch = FBI(mid, r);
	if (lch == rch)
	{
		if (!lch)
		{
			putchar('B');
			return 0;
		}
		else if (lch == 1)
		{
			putchar('I');
			return 1;
		}
		else
		{
			putchar('F');
			return 2;
		}
	}
	else putchar('F');
	return 2;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", a);
	FBI(0, 1 << n);
	return 0;
}