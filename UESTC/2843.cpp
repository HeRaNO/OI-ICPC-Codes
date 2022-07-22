#include <cstdio>
#include <cstring>
#define MAXN 100005

char s[MAXN];
int n, c[MAXN], pre[MAXN], las[26], cnt[26];
bool mov[MAXN];

int lowbit(int x){ return x & -x; }
int query(int x){ int r = 0; for (; x; x -= lowbit(x)) r += c[x]; return r; }
void add(int x){ for (; x <= n; x += lowbit(x)) ++c[x]; return ; }

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		int x = s[i] - 'a';
		++cnt[x];
		pre[i] = las[x]; las[x] = i;
	}
	int x = 0;
	for (int i = 0; i < 26; i++)
		if (cnt[i] & 1 && ++x > (n & 1))
			return puts("Impossible"), 0;
	int L = n, y = 0; long long ans = 0;
	for (int i = 1; i <= n; i++)
		if (!mov[i])
		{
			int x = s[i] - 'a';
			if (i < las[x])
			{
				ans += L + y - las[x] + query(las[x]);
				mov[las[x]] = true;
				add(las[x]);
				las[x] = pre[las[x]]; L -= 2;
			}
			else
				ans += --L >> 1;
			++y;
		}
	printf("%lld\n", ans);
	return 0;
}