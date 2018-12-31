#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

struct node
{
	int b[30], c, f;
};

int n, T, top, tot, ans;
vector <node> tree;
node t;
char s[30];

void Build_Tire_Tree(int dep, int x, int len)
{
	if (tree[x].b[s[dep] - 'a'] == -1)
	{
		top++;
		for (int i = 0; i <= 25; i++) t.b[i] = -1;
		t.c = 0;
		t.f = 0;
		tree.push_back(t);
		tree[x].b[s[dep] - 'a'] = top;
	}
	if (dep + 1 == len)
	{
		tree[tree[x].b[s[dep] - 'a']].c++;
		return ;
	}
	Build_Tire_Tree(dep + 1, tree[x].b[s[dep] - 'a'], len);
}

bool judge(int dep, int x, int len)
{
	if (dep == len)
	{
		if (tree[x].c > 0) return true;
		else return false;
	}
	if (tree[x].b[s[dep] - 'a'] == -1) return false;
	else return judge(dep + 1, tree[x].b[s[dep] - 'a'], len);
}

void dfs(int dep, int x, int flag, int len)
{
	if (dep == len)
	{
		if (!flag)
		{
			for (int i = 0; i <= 25; i++)
				if (tree[x].b[i] != -1 && tree[tree[x].b[i]].f != tot)
				{
					ans += tree[tree[x].b[i]].c;
					tree[tree[x].b[i]].f = tot;
				}
		}
		if (tree[x].f != tot && tree[x].c > 0)
		{
			ans += tree[x].c;
			tree[x].f = tot;
		}
		return ;
	}
	if (tree[x].b[s[dep] - 'a'] != -1) dfs(dep + 1, tree[x].b[s[dep] - 'a'], flag, len);
	if (!flag)
	{
		dfs(dep + 1, x, 1, len);
		for (int i = 0; i <= 25; i++)
			if (tree[x].b[i] != -1)
			{
				dfs(dep + 1, tree[x].b[i], 2, len);
				dfs(dep, tree[x].b[i], 3, len);
			}
	}
}

int main()
{
	for (int i = 0; i <= 25; i++) t.b[i] = -1;
	t.c = 0;
	tree.push_back(t);
	scanf("%d %d", &n, &T);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		Build_Tire_Tree(0, 0, strlen(s));
	}
	while (T--)
	{
		scanf("%s", s);
		if (judge(0, 0, strlen(s))) puts("-1");
		else
		{
			tot++;
			ans = 0;
			dfs(0, 0, 0, strlen(s));
			printf("%d\n", ans);
		}
	}
	return 0;
}
