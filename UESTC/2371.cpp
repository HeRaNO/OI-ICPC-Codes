#include <cstdio>
#include <algorithm>
#define MAXN 10005
using namespace std;

struct SplayTree
{
	int ch[2], father;
	bool rev;
};

SplayTree tree[MAXN];
int n, T, o, u, v, w[MAXN];
int sta[MAXN], top;

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
	for (int i = 0; x; i = x, x = tree[x].father) Splay(x), tree[x].ch[1] = i;
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
	x = 0; char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '+'){ x = 0; return ; }
		if (ch == '-'){ x = 1; return ; }
		if (ch == '?'){ x = 2; return ; }
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(T);
	while (T--)
	{
		read(o);
		read(u);
		read(v);
		if (!o) Link(u, v);
		else if (o == 1) Cut(u, v);
		else puts(getroot(u) != getroot(v) ? "No" : "Yes");
	}
	return 0;
}
