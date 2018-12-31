#include <cstdio>
#include <cstring>
#define MAXN 55
using namespace std;

int n, T;
int to[MAXN][MAXN];
bool state[MAXN];
int result[MAXN];
int ans, cnt, x;
int atschool[MAXN], backhome[MAXN];

bool Hungary(int x)
{
	for (int i = 1; i <= to[x][0]; i++)
	{
		if (state[to[x][i]]) continue;
		state[to[x][i]] = true;
		if (!result[to[x][i]] || Hungary(result[to[x][i]]))
		{
			result[to[x][i]] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	//freopen("stay.in","r",stdin);freopen("stay.out","w",stdout);
	scanf("%d", &T);
	while (T--)
	{
		memset(to, 0, sizeof(to));
		memset(result, 0, sizeof(result));
		scanf("%d", &n);
		cnt = 0;
		ans = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &atschool[i]);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &backhome[i]);
			if (!atschool[i] || (atschool[i] && !backhome[i])) cnt++;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &x);
				if (x && ((atschool[i] && !backhome[i]) || !atschool[i]) && atschool[j]) to[i][++to[i][0]] = j;
			}
			if (atschool[i] && !backhome[i]) to[i][++to[i][0]] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			memset(state, false, sizeof(state));
			if (Hungary(i)) ans++;
		}
		if (ans == cnt) printf("^_^\n");
		else printf("T_T\n");
	}
	return 0;
}
