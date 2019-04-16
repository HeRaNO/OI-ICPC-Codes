#include <cstdio>
#include <vector>
#define MAXN 100010
using namespace std;

long long a[MAXN], b[MAXN], s[MAXN], t[MAXN];
int n, m, nxt[MAXN];
vector <int> ans;

inline void GetNext(long long S[])
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

inline int KMP(long long S[], long long T[])
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
				ans.push_back(i - m + 1);
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
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
	for (int i = 1; i < n; i++) s[i - 1] = a[i] - a[i + 1];
	for (int i = 1; i < m; i++) t[i - 1] = b[i + 1] - b[i];
	GetNext(t);
	printf("%d\n", KMP(s, t));
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
	return 0;
}