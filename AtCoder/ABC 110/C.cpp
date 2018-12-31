#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

char s[MAXN], t[MAXN];
int n, v[MAXN], pre[26];

int main()
{
	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	memset(pre, -1, sizeof pre);
	for (int i = 0; i < n; i++)
	{
		v[i] = pre[s[i] - 'a'];
		pre[s[i] - 'a'] = i;
	}
	memset(pre, -1, sizeof pre);
	for (int i = 0; i < n; i++)
	{
		if (pre[t[i] - 'a'] != v[i])
		{
			puts("No");
			return 0;
		}
		pre[t[i] - 'a'] = i;
	}
	puts("Yes");
	return 0;
}