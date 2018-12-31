#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXL 105

int n, l, ans;
long long h, M = 1e9 + 13LL;
char s[MAXL];
long long a[20000];

int main()
{
	n = 20000;
	l = 100;
	//n=7;l=4;
	for (int c = 1; c <= n; c++)
	{
		scanf("%s", s);
		h = 0LL;
		for (int i = 0, v; i < l; i++)
		{
			if (s[i] >= '0' && s[i] <= '9') v = s[i] - '0';
			else if (s[i] >= 'A' && s[i] <= 'Z') v = s[i] - 'A' + 10;
			else v = s[i] - 'a' + 36;
			h = (h * 137LL + v + 5) % M;
		}
		a[c] = h;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) if (a[i - 1] != a[i]) ++ans;
	printf("%d\n", ans);
	return 0;
}