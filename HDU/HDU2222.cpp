#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 500010
using namespace std;

struct Tire
{
	int fail;
	int nxt[26];
	int cnt;
};

Tire tree[MAXN];
int n, T, root, top;
char key[51], des[1000005];
queue <int> q;

inline void pre_work()
{
	memset(tree, -1, sizeof tree);
	//memset(tree[MAXN].nxt,-1,500000*26);
	root = top = 0;
}

inline void add()
{
	int len = strlen(key);
	int now = root;
	for (int i = 0; i < len; i++)
	{
		if (tree[now].nxt[key[i] - 'a'] == -1)
			tree[now].nxt[key[i] - 'a'] = ++top;
		now = tree[now].nxt[key[i] - 'a'];
	}
	if (tree[now].cnt == -1) tree[now].cnt = 1;
	else tree[now].cnt++;
	return ;
}

inline void get_fail()
{
	q.push(root);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < 26; i++)
		{
			if (tree[u].nxt[i] != -1)
			{
				if (u == root) tree[tree[u].nxt[i]].fail = root;
				else
				{
					int now = tree[u].fail;
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
}

inline int Aho_Corasick_Automation()
{
	int ans = 0, len = strlen(des), now = root, cur;
	for (int i = 0; i < len; i++)
	{
		while (tree[now].nxt[des[i] - 'a'] == -1 && now != root)
			now = tree[now].fail;
		now = tree[now].nxt[des[i] - 'a'];
		if (now == -1) now = root;
		cur = now;
		while (cur != root && tree[cur].cnt != -1)
		{
			ans += tree[cur].cnt;
			tree[cur].cnt = -1;
			cur = tree[cur].fail;
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		pre_work();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", key);
			add();
		}
		get_fail();
		scanf("%s", des);
		printf("%d\n", Aho_Corasick_Automation());
	}
	return 0;
}
