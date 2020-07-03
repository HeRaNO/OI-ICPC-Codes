#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

char a[MAXN], b[MAXN];
int n, m, nxt[MAXN], ans[MAXN];

inline void getNext()
{
	int i = 0, j = -1;
	nxt[0] = -1;
	while (i != m)
	{
		if (!~j || b[i] == b[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
	return ;
}

inline void doKMP()
{
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (!~j || a[i] == b[j])
		{
			++i; ++j;
			if (j == m)
			{
				ans[++ans[0]] = i - m + 1;
				j = nxt[j - 1]; --i;
			}
		}
		else j = nxt[j];
	}
	return ;
}

int main()
{
	scanf("%s", a); n = strlen(a);
	scanf("%s", b); m = strlen(b);
	getNext(); doKMP();
	for (int i = 1; i <= ans[0]; i++)
		printf("%d%c", ans[i], i == ans[0] ? '\n' : ' ');
	return 0;
}