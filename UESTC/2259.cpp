#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

struct Trie
{
	int fail,nxt[26],cnt;
};

Trie tree[MAXN];
int n, T, root, top, cnt[MAXN], p[MAXN];
char s[MAXN];
int q[MAXN],l,r;

inline int newnode()
{
	memset(tree[top].nxt, -1, sizeof tree[top].nxt);
	tree[top].fail = -1;
	tree[top++].cnt = 0;
	return top - 1;
}

inline void add(char S[],int id)
{
	int len = strlen(S);
	int now = root;
	for (int i = 0; i < len; i++)
	{
		if (!~tree[now].nxt[S[i] - 'a']) tree[now].nxt[S[i] - 'a'] = newnode();
		now = tree[now].nxt[S[i] - 'a'];
		++tree[now].cnt;
	}
	p[id] = now;
	return ;
}

inline void push(int x){q[++r]=x;return ;}
inline void pop(){++l;return ;}
inline int front(){return q[l];}
inline bool empty(){return l>r;}

inline void Get_Fail()
{
	int u, now;l=1;
	tree[root].fail=root;
	for (int i=0;i<26;i++)
	{
		if (!~tree[root].nxt[i]) tree[root].nxt[i]=root;
		else {tree[tree[root].nxt[i]].fail=root;push(tree[root].nxt[i]);}
	}
	while (!empty())
	{
		u = front();
		pop();
		for (int i = 0; i < 26; i++)
		{
			if (!~tree[u].nxt[i]) tree[u].nxt[i]=tree[tree[u].fail].nxt[i];
			else
			{
				tree[tree[u].nxt[i]].fail=tree[tree[u].fail].nxt[i];
				push(tree[u].nxt[i]);
			}
		}
	}
	for (int i=r;i;i--) tree[tree[q[i]].fail].cnt+=tree[q[i]].cnt;
	return ;
}

int main()
{
	scanf("%d", &n);root=newnode();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);add(s, i);
	}
	Get_Fail();
	for (int i=1;i<=n;i++) printf("%d\n",tree[p[i]].cnt);
	return 0;
}