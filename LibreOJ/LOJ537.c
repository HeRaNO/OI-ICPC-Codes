#include <stdio.h>
#include <string.h>
#define MAXN 5000010
#define MAXR 20

char a[MAXN];
int n, m, k, cnt[1 << MAXR], f[26], h, ans;
int DNA[MAXN];

int main()
{
	f['G' - 'A'] = 1;
	f['C' - 'A'] = 2;
	f['T' - 'A'] = 3;
	scanf("%s", a);
	n = strlen(a);
	scanf("%d", &k);
	m = (1 << ((k - 1) << 1)) - 1;
	for (int i = 0; i < n; i++) DNA[i] = f[a[i] - 'A'];
	for (int i = 0; i < k - 1; i++) h = h << 2 | DNA[i];
	for (int i = k - 1; i < n; i++)
	{
		h = h << 2 | DNA[i];
		++cnt[h];
		h &= m;
	}
	for (int i = 0; i < (1 << (k << 1)); i++) if (ans < cnt[i]) ans = cnt[i];
	printf("%d\n", ans);
	return 0;
}
