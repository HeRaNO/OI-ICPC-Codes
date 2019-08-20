#include <bits/stdc++.h>
#define MAXN 50001
using namespace std;

struct Trie
{
	int nxt[94], tim[94], id1, id2;
};

Trie tree[300001];
int root, top, pos;
int n,k,m,mn[MAXN][2];
char a[MAXN][7],s[MAXN][7];

inline int newnode()
{
	tree[top].id1 = tree[top].id2 = -1;++top;
	return top - 1;
}

inline void add(int pt,int id, int len)
{
	int now = root;
	for (int i = 0; i < len; i++)
	{
		if (tree[now].tim[s[id][i] - 33]!=pt)
		{
			tree[now].tim[s[id][i] - 33] = pt;
			tree[now].nxt[s[id][i] - 33] = newnode();
		}
		now = tree[now].nxt[s[id][i] - 33];
	}
	if (!~tree[now].id1) tree[now].id1=id;
	else if (!~tree[now].id2) tree[now].id2=id;
	return ;
}

inline int query(int id, int len)
{
	int now = root;
	for (int i = 0; i < len; i++) now = tree[now].nxt[s[id][i] - 33];
	if (tree[now].id1!=id) return tree[now].id1;
	return tree[now].id2;
}

int main()
{
	freopen("similar.in","r",stdin);
	freopen("similar.out","w",stdout);
	memset(mn,0x3f,sizeof mn);
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%s",a[i]);
	for (int i=0;i<(1<<k);i++)
	{
		top = 0;root = newnode();
		memset(tree[root].nxt,0,sizeof tree[root].nxt);
		int x=__builtin_popcount(i);
		for (int p=1;p<=n;p++)
		{
			pos=0;
			for (int j=0;j<k;j++) if (i&(1<<j)) s[p][pos++]=a[p][j];
			s[p][pos]=0;
			add(i+1,p,x);
		}
		x=k-x;
		for (int p=1;p<=n;p++)
			if (mn[p][0]>x)
			{
				int res=query(p,k-x);
				if (!~res) continue;
				mn[p][0]=x;mn[p][1]=res;
			}
	}
	for (int i=1;i<=n;i++) printf("%d %d\n",mn[i][0],mn[i][1]);
	return 0;
}