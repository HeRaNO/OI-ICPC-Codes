#include <cstdio>
#include <cstring>
#define MAXN 110
using namespace std;

int road[MAXN][MAXN];
bool state[MAXN];
int result[MAXN];
int n, m;
int ans;
char ch[MAXN];

bool Hungary(int x)
{
	for (int i = 1; i <= road[x][0]; i++)
	{
		if (state[road[x][i]]) continue;
		state[road[x][i]] = true;
		if (!result[road[x][i]] || Hungary(result[road[x][i]]))
		{
			result[road[x][i]] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		gets(ch);
		for (int j = 0; j < m; j++)
		{
			if (ch[j] == '1')
				road[i][++road[i][0]] = j;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		memset(state, false, sizeof(state));
		if (Hungary(i)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}