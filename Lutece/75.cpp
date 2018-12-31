#include <bits/stdc++.h>
#define MAXK 20
#define MAXN 110
using namespace std;

int n, k, a[MAXN], dio, diosama = ~(1 << 31), ans;
char s[MAXK];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < k; j++) a[i] = (a[i] << 1) | (s[j] - '0');
	}
	for (int i = 0; i < (1 << k); i++)
	{
		dio = 0;
		for (int j = 1; j <= n; j++)
		{
			int x = a[j] ^ i, cnt = 0;
			for (; x; x >>= 1) if (x & 1) ++cnt;
			dio = max(dio, cnt);
		}
		if (dio < diosama)
		{
			ans = i;
			diosama = dio;
		}
	}
	for (int i = 0; i < k; i++) a[i] = ans & 1, ans >>= 1;
	for (int i = k - 1; ~i; i--) putchar(a[i] + '0');
	putchar('\n');
	return 0;
}
