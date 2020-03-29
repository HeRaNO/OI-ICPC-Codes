#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
using namespace std;
const int N = 200050;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
namespace SAM
{
/* Claris's Templet */
constexpr int MAXN = N;
int tot = 1, last = 1, pre[MAXN << 1], son[MAXN << 1][26], ml[MAXN << 1], pos[MAXN << 1], endpos[MAXN << 1];
int fa[MAXN << 1][20];
void extend(int w, int rr)
{
	int p = ++tot, x = last, r, q;
	for (ml[last = p] = ml[x] + 1, endpos[p] = ml[last]; x && !son[x][w]; x = pre[x])
		son[x][w] = p;
	if (!x)
		pre[p] = 1;
	else if (ml[x] + 1 == ml[q = son[x][w]])
		pre[p] = q;
	else
	{
		pre[r = ++tot] = pre[q];
		endpos[r] = endpos[q];
		memcpy(son[r], son[q], sizeof son[r]);
		ml[r] = ml[x] + 1;
		pre[p] = pre[q] = r;
		for (; x && son[x][w] == q; x = pre[x])
			son[x][w] = r;
	}
	pos[rr] = p;
	endpos[pre[p]] = rr;
	return;
}
void Doubling()
{
	for (int i = 1; i <= tot; i++)
		fa[i][0] = pre[i];
	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= tot; i++)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	return;
}
int getpos(int l, int r)
{
	int len = r - l + 1, pt = pos[r];
	for (int i = 19; ~i; i--)
		if (ml[fa[pt][i]] >= len)
			pt = fa[pt][i];
	return pt;
}
} // namespace SAM
using namespace SAM;
char s[N], t[N];
int n, m;

void solve()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		extend(s[i] - 'A', i);
	scanf("%d", &m);
	while (m--)
	{
		scanf("%s", t + 1);
		int sz = strlen(t + 1);
		int ans = 0;
		for (int i = 1; i <= sz; ++i)
		{
			if (son[1][t[i] - 'A'] == 0)
			{
				ans = -1;
				break;
			}
		}
		if (ans == -1)
		{
			puts("-1");
			continue;
		}
		for (int i = 1; i <= sz; ++i)
		{
			int now = 1;
			while (t[i] && son[now][t[i] - 'A'])
				now = son[now][t[i++] - 'A'];
			i--;
			ans++;
		}
		cout << ans << '\n';
	}
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}