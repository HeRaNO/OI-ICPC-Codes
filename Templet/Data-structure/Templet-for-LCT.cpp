#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct SplayTree
{
	int ch[2], father;
	int sum;
	bool rev;
};

SplayTree tree[MAXN];
int n, T, opt, u, v, w[MAXN];
int sta[MAXN], top;

inline void Push_Up(int x)
{
	int l = tree[x].ch[0], r = tree[x].ch[1];
	tree[x].sum = tree[l].sum + tree[r].sum + w[x];
	return ;
}

inline void Push_Down(int x)
{
	int l = tree[x].ch[0], r = tree[x].ch[1];
	if (tree[x].rev)
	{
		tree[x].rev = false;
		tree[l].rev ^= 1;
		tree[r].rev ^= 1;
		swap(tree[x].ch[0], tree[x].ch[1]);
	}
	return ;
}

inline bool isroot(int x)
{
	return !(tree[tree[x].father].ch[0] == x || tree[tree[x].father].ch[1] == x);
}

inline void Rotate(int &x)
{
	int y = tree[x].father, z = tree[y].father, l, r;
	l = (tree[y].ch[1] == x);
	r = l ^ 1;
	if (!isroot(y)) tree[z].ch[tree[z].ch[1] == y] = x;
	tree[x].father = z;
	tree[y].father = x;
	tree[tree[x].ch[r]].father = y;
	tree[y].ch[l] = tree[x].ch[r];
	tree[x].ch[r] = y;
	Push_Up(y);
	Push_Up(x);
	return ;
}

inline void Splay(int x)
{
	top = 0;
	sta[++top] = x;
	for (int i = x; !isroot(i); i = tree[i].father) sta[++top] = tree[i].father;
	while (top) Push_Down(sta[top--]);
	while (!isroot(x))
	{
		int y = tree[x].father, z = tree[y].father;
		if (!isroot(y))
		{
			if (tree[y].ch[0] == x ^ tree[z].ch[0] == y) Rotate(x);
			else Rotate(y);
		}
		Rotate(x);
	}
	return ;
}

inline void Access(int x)
{
	for (int i = 0; x; i = x, x = tree[x].father) Splay(x), tree[x].ch[1] = i, Push_Up(x);
	return ;
}

inline void Makeroot(int x)
{
	Access(x);
	Splay(x);
	tree[x].rev ^= 1;
	return ;
}

inline void Link(int x, int y)
{
	Makeroot(x);
	tree[x].father = y;
	return ;
}

inline void Cut(int x, int y)
{
	Makeroot(x);
	Access(y);
	Splay(y);
	tree[y].ch[0] = tree[x].father = 0;
	return ;
}

inline int getroot(int x)
{
	Access(x);
	Splay(x);
	while (tree[x].ch[0]) x = tree[x].ch[0];
	return x;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	read(T);
	for (int i = 1; i <= n; i++) read(w[i]), tree[i].sum = w[i];
	while (T--)
	{
		read(opt);
		read(u);
		read(v);
		if (!opt) Link(u, v); //Link a<->b
		else if (opt == 1) Cut(u, v) //Cut a<->b
			else if (opt == 3) //Change the weight of point u to v
			{
				Makeroot(u);
				w[u] = v;
				Push_Up(u);
			}
			else//Query the sum of weight on link u->v
			{
				if (getroot(u) != getroot(v)) puts("impossible");
				else
				{
					Makeroot(u);
					Access(v);
					Splay(v);
					printf("%d\n", tree[v].sum);
				}
			}
	}
	return 0;
}
