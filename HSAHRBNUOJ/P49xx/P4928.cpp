#include <cstdio>
using namespace std;

long long f[21], ans;
char s[20];
int cnt[26], n;

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	f[0] = 1LL;
	for (int i = 1; i <= n; i++) ++cnt[s[i] - 'a'], f[i] = f[i - 1] * i;
	ans = f[n];
	for (int i = 0; i < 26; i++) ans /= f[cnt[i]];
	printf("%lld\n", ans);
	return 0;
}