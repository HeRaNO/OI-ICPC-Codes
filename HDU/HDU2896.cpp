#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100001
using namespace std;

struct Tire
{
	int fail;
	int nxt[128];
	int id;
};

Tire tree[MAXN];
int n, T, root, top, ans;
char des[10001];
bool vis[501];
queue <int> q;

inline int newnode()
{
	for (int i = 0; i < 128; i++) tree[top].nxt[i] = -1;
	tree[top++].id = -1;
	tree[top].fail = -1;
	return top - 1;
}

inline void pre_work()
{
	top = 0;
	root = newnode();
	ans = 0;
	return ;
}

inline void add(int id)
{
	int len = strlen(des);
	int now = root;
	for (int i = 0; i < len; i++)
	{
		if (tree[now].nxt[des[i]] == -1)
			tree[now].nxt[des[i]] = newnode();
		now = tree[now].nxt[des[i]];
	}
	tree[now].id = id;
	return ;
}

inline void get_fail()
{
	int u, now;
	q.push(root);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (int i = 0; i < 128; i++)
		{
			if (tree[u].nxt[i] != -1)
			{
				if (u == root) tree[tree[u].nxt[i]].fail = root;
				else
				{
					now = tree[u].fail;
					while (now != -1)
					{
						if (tree[now].nxt[i] != -1)
						{
							tree[tree[u].nxt[i]].fail = tree[now].nxt[i];
							break;
						}
						now = tree[now].fail;
					}
					if (now == -1) tree[tree[u].nxt[i]].fail = root;
				}
				q.push(tree[u].nxt[i]);
			}
		}
	}
	return ;
}

inline bool Aho_Corasick_Automation(int id)
{
	int len = strlen(des), now = root, cur;
	bool flag = false;
	memset(vis, false, sizeof vis);
	for (int i = 0; i < len; i++)
	{
		while (tree[now].nxt[des[i]] == -1 && now != root)
			now = tree[now].fail;
		now = tree[now].nxt[des[i]];
		if (now == -1) now = root;
		cur = now;
		while (cur != root && tree[cur].id != -1)
		{
			vis[tree[cur].id] = true;
			flag = true;
			cur = tree[cur].fail;
		}
	}
	if (!flag) return flag;
	printf("web %d:", id);
	for (int i = 1; i <= n; i++)
		if (vis[i]) printf(" %d", i);
	puts("");
	return flag;
}

int main()
{
	while (~scanf("%d", &n))
	{
		pre_work();//getchar();
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", des);
			add(i);
		}
		get_fail();
		scanf("%d", &T); //getchar();
		for (int i = 1; i <= T; i++)
		{
			scanf("%s", des);
			if (Aho_Corasick_Automation(i)) ans++;
		}
		printf("total: %d\n", ans);
	}
	return 0;
}

