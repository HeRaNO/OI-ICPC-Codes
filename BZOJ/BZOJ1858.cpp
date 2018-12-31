#include <cstdio>
#include <algorithm>
using namespace std;

struct data
{
	int suf[2], pre[2], ans[2], sum[2], all_same;
};

struct SegmentTree
{
	int p, r, m, lazy, rev;
	data w;
};

SegmentTree tree[1 << 18];
int n, T, opt, l, r;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

inline data Push_Up(data a, data b)
{
	data res;
	for (int i = 0; i <= 1; i++)
	{
		res.pre[i] = a.pre[i];
		res.suf[i] = b.suf[i];
		res.ans[i] = mymax(a.ans[i], mymax(b.ans[i], a.suf[i] + b.pre[i]));
		res.sum[i] = a.sum[i] + b.sum[i];
	}
	if (a.all_same == b.all_same) res.all_same = a.all_same;
	else res.all_same = -1;
	if (~a.all_same) res.pre[a.all_same] += b.pre[a.all_same];
	if (~b.all_same) res.suf[b.all_same] += a.suf[b.all_same];
	return res;
}

inline void Make_Same(int u, int v)
{
	tree[u].rev = 0;
	tree[u].w.all_same = tree[u].lazy = v;
	int len = tree[u].r - tree[u].p;
	tree[u].w.pre[v] = tree[u].w.suf[v] = tree[u].w.ans[v] = tree[u].w.sum[v] = len;
	v ^= 1;
	tree[u].w.pre[v] = tree[u].w.suf[v] = tree[u].w.ans[v] = tree[u].w.sum[v] = 0;
	return ;
}

inline void Rev(int u)
{
	tree[u].rev ^= 1;
	swap(tree[u].w.pre[0], tree[u].w.pre[1]);
	swap(tree[u].w.suf[0], tree[u].w.suf[1]);
	swap(tree[u].w.ans[0], tree[u].w.ans[1]);
	swap(tree[u].w.sum[0], tree[u].w.sum[1]);
	if (~tree[u].w.all_same) tree[u].w.all_same ^= 1;
	return ;
}

inline void Push_Down(int u)
{
	if (~tree[u].lazy)
	{
		Make_Same(u << 1, tree[u].lazy);
		Make_Same(u << 1 | 1, tree[u].lazy);
		tree[u].lazy = -1;
	}
	if (tree[u].rev)
	{
		Rev(u << 1);
		Rev(u << 1 | 1);
		tree[u].rev = 0;
	}
	return ;
}

inline void Build_A_Tree(int u)
{
	tree[u].lazy = -1;
	if (tree[u].p + 1 == tree[u].r)
	{
		read(tree[u].w.all_same);
		if (tree[u].w.all_same)
			tree[u].w.pre[1] = tree[u].w.suf[1] = tree[u].w.ans[1] = tree[u].w.sum[1] = 1;
		else
			tree[u].w.pre[0] = tree[u].w.suf[0] = tree[u].w.ans[0] = tree[u].w.sum[0] = 1;
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	tree[u].w = Push_Up(tree[u << 1].w, tree[u << 1 | 1].w);
	return ;
}

inline void rev_to_x(int u, int l, int r, int x)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		Make_Same(u, x);
		return ;
	}
	Push_Down(u);
	if (r <= tree[u].m) rev_to_x(u << 1, l, r, x);
	else if (tree[u].m <= l) rev_to_x(u << 1 | 1, l, r, x);
	else
	{
		rev_to_x(u << 1, l, tree[u].m, x);
		rev_to_x(u << 1 | 1, tree[u].m, r, x);
	}
	tree[u].w = Push_Up(tree[u << 1].w, tree[u << 1 | 1].w);
	return ;
}

inline void rev_all(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		Rev(u);
		return ;
	}
	Push_Down(u);
	if (r <= tree[u].m) rev_all(u << 1, l, r);
	else if (tree[u].m <= l) rev_all(u << 1 | 1, l, r);
	else
	{
		rev_all(u << 1, l, tree[u].m);
		rev_all(u << 1 | 1, tree[u].m, r);
	}
	tree[u].w = Push_Up(tree[u << 1].w, tree[u << 1 | 1].w);
	return ;
}

inline data query_1(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].w;
	Push_Down(u);
	if (r <= tree[u].m) return query_1(u << 1, l, r);
	else if (tree[u].m <= l) return query_1(u << 1 | 1, l, r);
	else return Push_Up(query_1(u << 1, l, tree[u].m), query_1(u << 1 | 1, tree[u].m, r));
}

int main()
{
	read(n);
	read(T);
	tree[1].p = 0;
	tree[1].r = n;
	Build_A_Tree(1);
	while (T--)
	{
		read(opt);
		read(l);
		read(r);
		switch (opt)
		{
		case 0:
			rev_to_x(1, l, r + 1, 0);
			break;
		case 1:
			rev_to_x(1, l, r + 1, 1);
			break;
		case 2:
			rev_all(1, l, r + 1);
			break;
		case 3:
			printf("%d\n", query_1(1, l, r + 1).sum[1]);
			break;
		case 4:
			printf("%d\n", query_1(1, l, r + 1).ans[1]);;
			break;
		}
	}
	return 0;
}