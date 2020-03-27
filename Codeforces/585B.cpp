#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n, k;
char s[5][105];
queue<pii> q;
map<pii, bool> vis;
pii S;
bool bfs()
{
	while (!q.empty())
		q.pop();
	vis.clear();
	q.push(S);
	vis[S] = 1;
	while (!q.empty())
	{
		pii u = q.front();
		q.pop();
		pii nxt = u;
		nxt.second++;
		if (nxt.second > n)
			return true;
		if (s[nxt.first][nxt.second] >= 'A' && s[nxt.first][nxt.second] <= 'Z')
			continue;
		for (int i = -1; i <= 1; ++i)
		{
			nxt.first = u.first + i;
			if (nxt.first == 0 || nxt.first == 4)
				continue;
			if (s[nxt.first][nxt.second] >= 'A' && s[nxt.first][nxt.second] <= 'Z')
				continue;
			if (s[nxt.first][nxt.second + 1] >= 'A' && s[nxt.first][nxt.second + 1] <= 'Z')
				continue;
			if (s[nxt.first][nxt.second + 2] >= 'A' && s[nxt.first][nxt.second + 2] <= 'Z')
				continue;
			nxt.second += 2;
			if (!vis[nxt])
			{
				vis[nxt] = 1;
				q.push(nxt);
			}
			nxt.second -= 2;
		}
	}
	return false;
}

void solve()
{
	cin >> n >> k;
	mem(s, 0, -4, s);
	for (int i = 1; i <= 3; ++i)
	{
		scanf("%s", s[i] + 1);
		if (s[i][1] == 's')
			S.first = i;
	}
	S.second = 1;
	bool flag = bfs();
	if (flag)
		puts("YES");
	else
		puts("NO");
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}