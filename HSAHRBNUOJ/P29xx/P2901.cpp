#include <cstdio>
#include <cstring>
#define MAXN 10010
#define MAXL 15
using namespace std;

struct Tire
{
	int nxt[10];
	bool ed;
};

Tire tree[MAXN * MAXL];
int n, T, root, top;
char S[MAXL];
bool flag;

inline int newnode()
{
	memset(tree[top].nxt, -1, sizeof tree[top].nxt);
	tree[top].ed = false;
	top++;
	return top - 1;
}

inline void add()
{
	int len = strlen(S), now = root;
	for (int i = 0; i < len; i++)
	{
		if (!~tree[now].nxt[S[i] - '0']) tree[now].nxt[S[i] - '0'] = newnode();
		now = tree[now].nxt[S[i] - '0'];
	}
	tree[now].ed = true;
	return ;
}

inline bool dfs(int x)
{
	if (tree[x].ed)
	{
		for (int i = 0; i <= 9; i++) if (~tree[x].nxt[i]) return true;
	}
	bool res = false;
	for (int i = 0; i <= 9; i++) if (~tree[x].nxt[i]) res = res || dfs(tree[x].nxt[i]);
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		top = 0;
		root = newnode();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", S);
			add();
		}
		if (dfs(root)) puts("NO");
		else puts("YES");
	}
	return 0;
}
