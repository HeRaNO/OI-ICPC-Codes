#include <cstdio>
#define MAXN 1000010
using namespace std;

int n, cnt[26], mn[26][26], pre[26], pos[26][26], ans, now;
char a[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", a);
	for (int i = 0; i < n; i++)
	{
		now = a[i] - 'a';
		pre[now] = i;
		cnt[now]++;
		for (int j = 0; j < 26; j++)
			if (j != now && cnt[j])
			{
				ans = mymax(ans, cnt[now] - cnt[j] - mn[now][j] - (pre[j] == pos[now][j]));
				ans = mymax(ans, cnt[j] - cnt[now] - mn[j][now] - (pre[j] == pos[j][now]));
			}
		for (int j = 0; j < 26; j++)
		{
			if (cnt[now] - cnt[j] < mn[now][j]) mn[now][j] = cnt[now] - cnt[j], pos[now][j] = i;
			if (cnt[j] - cnt[now] < mn[j][now]) mn[j][now] = cnt[j] - cnt[now], pos[j][now] = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}