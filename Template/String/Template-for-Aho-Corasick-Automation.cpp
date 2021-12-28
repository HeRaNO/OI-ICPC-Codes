#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 1010
#define MAXL 110
using namespace std;

struct Tire
{
	int fail;
	int nxt[94];
	int id;
};

Tire tree[MAXN * MAXL];
int root, top;
bool appear[MAXN];
queue <int> q;

inline int newnode()
{
	memset(tree[top].nxt, -1, sizeof tree[top].nxt);
	tree[top].fail = -1;
	tree[top++].id = -1;
	return top - 1;
}

inline void add(char S[], int id)
{
	int len = strlen(S);
	int now = root;
	for (int i = 0; i < len; i++)
	{
		if (!~tree[now].nxt[S[i] - 33]) tree[now].nxt[S[i] - 33] = newnode();
		now = tree[now].nxt[S[i] - 33];
	}
	tree[now].id = id;
	return ;
}

inline void Get_Fail()
{
	int u, now;
	q.push(root);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (int i = 0; i < 94; i++)
			if (~tree[u].nxt[i])
			{
				if (u == root) tree[tree[u].nxt[i]].fail = root;
				else
				{
					now = tree[u].fail;
					while (~now)
					{
						if (~tree[now].nxt[i])
						{
							tree[tree[u].nxt[i]].fail = tree[now].nxt[i];
							break;
						}
						now = tree[now].fail;
					}
					if (!~now) tree[tree[u].nxt[i]].fail = root;
				}
				q.push(tree[u].nxt[i]);
			}
	}
	return ;
}

inline int Aho_Corasick_Automation(char S[])
{
	int len = strlen(S), cur, now = root, cnt = 0;
	memset(appear, false, sizeof appear);
	for (int i = 0; i < len; i++)
	{
		while (!~tree[now].nxt[S[i] - 33] && now != root) now = tree[now].fail;
		now = tree[now].nxt[S[i] - 33];
		if (!~now) now = root;
		cur = now;
		while (cur != root && ~tree[now].id)
		{
			appear[tree[cur].id] = true;
			cur = tree[cur].fail;
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	top = 0;
	root = newnode();
	Get_Fail();
	Aho_Corasick_Automation();
	return 0;
}
