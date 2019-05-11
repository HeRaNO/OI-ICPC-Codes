#include <cstdio>
#define MAXN 100010
#define LC tree[x].lc
#define RC tree[x].rc
using namespace std;

struct Penalty
{
	int a,b;
	Penalty(){}
	Penalty(int _a,int _b):a(_a),b(_b){}
	bool operator < (const Penalty &x) const{
		if (a==x.a) return b<x.b;
		return a>x.a;
	}
	bool operator == (const Penalty &x) const{
		return a==x.a&&b==x.b;
	}
	bool operator <= (const Penalty &x) const{
		return (*this == x) || (*this < x);
	}
};

struct SBT
{
	int lc, rc, siz, cnt;
	Penalty key;
	SBT() {}
	SBT(Penalty _key): lc(0), rc(0), siz(1), key(_key), cnt(1) {}
};

SBT tree[MAXN];
int n, T, opt, x, root, siz, a[MAXN][2], t, p;

inline void Push_Up(int x)
{
	tree[x].siz = tree[LC].siz + tree[RC].siz + tree[x].cnt;
	return ;
}

inline void rturn(int &x)
{
	int k = LC;
	LC = tree[k].rc;
	tree[k].rc = x;
	Push_Up(x);
	Push_Up(k);
	x = k;
	return ;
}

inline void lturn(int &x)
{
	int k = RC;
	RC = tree[k].lc;
	tree[k].lc = x;
	Push_Up(x);
	Push_Up(k);
	x = k;
	return ;
}

inline void Maintain(int &x, bool f)
{
	if (!f)
	{
		if (tree[tree[LC].lc].siz > tree[RC].siz) rturn(x);
		else if (tree[tree[RC].lc].siz > tree[RC].siz) lturn(x), rturn(x);
		else return ;
	}
	else
	{
		if (tree[tree[RC].rc].siz > tree[LC].siz) lturn(x);
		else if (tree[tree[LC].rc].siz > tree[LC].siz) rturn(x), lturn(x);
		else return ;
	}
	Maintain(LC, false);
	Maintain(RC, true);
	Maintain(x, false);
	Maintain(x, true);
	return ;
}

inline void add(int &x, Penalty v)
{
	if (!x)
	{
		tree[x = ++siz] = SBT(v);
		return ;
	}
	tree[x].siz++;
	if (tree[x].key == v) tree[x].cnt++;
	else
	{
		if (v < tree[x].key) add(LC, v);
		else add(RC, v);
		Maintain(x, tree[x].key <= v);
	}
	return ;
}

inline void del(int &x, Penalty v)
{
	if (!x) return ;
	tree[x].siz--;
	if (tree[x].key == v)
	{
		if (tree[x].cnt > 1)
		{
			tree[x].cnt--;
			return ;
		}
		if (!LC && !RC) x = 0;
		else if (!LC || !RC) x = LC + RC;
		else
		{
			int t = RC;
			while (tree[t].lc) t = tree[t].lc;
			tree[x].key = tree[t].key;
			del(RC, tree[t].key);
		}
	}
	else if (v < tree[x].key) del(LC, v);
	else del(RC, v);
	return ;
}

inline int getrank(int &x, Penalty v)
{
	if (!x) return -1;
	if (v < tree[x].key) return getrank(LC, v);
	else if (v == tree[x].key) return tree[LC].siz + 1;
	else return tree[LC].siz + tree[x].cnt + getrank(RC, v);
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);read(T);root=1;
	tree[siz=1]=SBT(Penalty(0,0));tree[1].siz=n;tree[1].cnt=n;
	while (T--)
	{
		read(t);read(p);
		del(root,Penalty(a[t][0],a[t][1]));
		++a[t][0];a[t][1]+=p;
		add(root,Penalty(a[t][0],a[t][1]));
		printf("%d\n",getrank(root, Penalty(a[1][0],a[1][1])));
	}
	return 0;
}
