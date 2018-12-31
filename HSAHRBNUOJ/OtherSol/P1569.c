#include <stdio.h>
#include <string.h>
#define MAXN 5000010

char a[MAXN];
int n, cnt[1 << 10], f[26], h, ans;
int DNA[MAXN];

int main()
{
	f['G' - 'A'] = 1;
	f['C' - 'A'] = 2;
	f['T' - 'A'] = 3;
	scanf("%s", a);
	n = strlen(a);
	for (int i = 0; i < n; i++) DNA[i] = f[a[i] - 'A'];
	for (int i = 0; i < 4; i++) h = h << 2 | DNA[i];
	for (int i = 4; i < n; i++)
	{
		h = h << 2 | DNA[i];
		++cnt[h];
		h &= 255;
	}
	for (int i = 0; i < (1 << 10); i++) if (ans < cnt[i]) ans = cnt[i];
	printf("%d\n", ans);
	return 0;
}
