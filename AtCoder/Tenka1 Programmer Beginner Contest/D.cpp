#include <cstdio>

int n, x, p = 1;
int a[450][450];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 450 && !x; i++)
		if ((i + 1)*i == (n << 1)) x = i;
	if (!x) return puts("No"), 0;
	puts("Yes");
	printf("%d\n", x + 1);
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= i; j++, p++)
			a[i][j] = p;
	for (int i = 1; i <= x; i++)
	{
		printf("%d", x);
		int xx = i, yy = 1;
		while (a[xx][yy]) printf(" %d", a[xx][yy++]);
		--yy;
		++xx;
		while (a[xx][yy]) printf(" %d", a[xx++][yy]);
		putchar('\n');
	}
	printf("%d", x);
	for (int i = 1; i <= x; i++) printf(" %d", a[i][i]);
	putchar('\n');
	return 0;
}