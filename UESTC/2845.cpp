#include <cstdio>
#define MAXN 20

char s[MAXN];
bool passed[MAXN];
int a[MAXN];

int main()
{
	scanf("%*d");
	scanf("%s", s);
	for (int i = 0; s[i]; i++)
		passed[s[i] - 'A'] = true;
	int ans = 0;
	for (int i = 0; i < 13; i++)
	{
		scanf("%d", &a[i]);
		if (!passed[i] && a[i] > a[ans])
			ans = i;
	}
	printf("%c\n", ans + 'A');
	return 0;
}