#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 210
using namespace std;

bool state[MAXN];
int result[MAXN];
int n, m;
int n1, flag;
int ans;
vector <int> to[MAXN];

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
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &n1);
		to[i].push_back(n1);
		while (n1--)
		{
			scanf("%d", &flag);
			to[i].push_back(flag);
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
