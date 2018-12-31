//Code By HeRaNO
#include<stdio.h>
#include<string.h>
int i, l, m, t;
char a[1010], c;
int main()
{
	gets(a);
	l = strlen(a);
	m = 0;
	c = a[0];
	t = 1;
	for (i = 1; i < l; i++)
	{
		if (a[i] == a[i - 1]) t++;
		else
		{
			if (t > m)
			{
				m = t;
				t = 1;
				c = a[i - 1];
			}
			else t = 1;
		}
	}
	if (t > m)
	{
		m = t;
		c = a[i - 1];
	}
	printf("%c %d\n", c, m);
	return 0;
}
