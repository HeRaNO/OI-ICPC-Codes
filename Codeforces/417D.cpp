#include <cstdio>
#include <vector>
#define MAXN 200005
using namespace std;

int a[MAXN], b[MAXN], s[MAXN], t[MAXN];
int n, m, nxt[MAXN];

inline void GetNext(int S[])
{
	int i = 0, j = -1;
	nxt[0] = -1;
	while (i != m - 1)
	{
		if (!~j || S[i] == S[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
	return ;
}

inline int KMP(int S[], int T[])
{
	int ret = 0;
	int i = 0, j = 0;
	while (i < n - 1 && j < m - 1)
	{
		if (!~j || S[i] == T[j])
		{
			++i; ++j;
			if (j == m - 1)
			{
				++ret; j = nxt[j - 1]; --i;
			}
		}
		else j = nxt[j];
	}
	return ret;
}

int main()
{
	scanf("%d", &n); scanf("%d", &m);
	if (n < m) return puts("0\n"), 0;
	if (m == 1) return printf("%d\n", n), 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	for (int i = 1; i < n; i++) s[i - 1] = a[i + 1] - a[i];
	for (int i = 1; i < m; i++) t[i - 1] = b[i + 1] - b[i];
	GetNext(t);
	printf("%d\n", KMP(s, t));
	return 0;
}