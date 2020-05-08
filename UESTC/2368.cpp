#include <bits/stdc++.h>
#define MAXN 300005
#define MAXM 1000005
using namespace std;

struct Triple
{
	int x,y,z;
	Triple(){}
	Triple(int _x,int _y,int _z=-1):x(_x),y(_y),z(_z){}
};

Triple a[MAXM],Q[MAXM];
int n,k,m,o,x,y,f[MAXN],ans[MAXM];
bool vis[MAXM];

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
inline bool same(int x,int y){return getf(x)==getf(y);}
inline void add(int x,int y)
{
	int fx=getf(x),fy=getf(y);
	if (fx!=fy) f[fy]=fx;
	return ;
}

inline void Merge(Triple a)
{
	int o=a.x,x=a.y,y=a.z;
	if (o==1)
	{
		assert(!same(x,y+n)&&!same(x,y+(n<<1)));
		add(x,y);add(x+n,y+n);add(x+(n<<1),y+(n<<1));
	}
	else
	{
		assert(!same(x,y)&&!same(x,y+n));
		add(x,y+(n<<1));add(x+n,y);add(x+(n<<1),y+n);
	}
	return ;
}

inline int Query(int x,int y)
{
	if (same(x,y)&&same(x+n,y+n)&&same(x+(n<<1),y+(n<<1))) return 0;
	if (same(x+n,y)&&same(x+(n<<1),y+n)&&same(x,y+(n<<1))) return 1;
	if (same(y+n,x)&&same(y+(n<<1),x+n)&&same(y,x+(n<<1))) return 2;
	return 3;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='q'){x=0;return ;}
		if (ch=='d'){x=1;return ;}
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(k);read(m);
	for (int i=1;i<=n*3;i++) f[i]=i;
	for (int i=1;i<=k;i++)
	{
		read(o);read(x);read(y);
		a[i]=Triple(o,x,y);
	}
	for (int i=1;i<=m;i++)
	{
		read(o);read(x);
		if (!o)
		{
			read(y);Q[i]=Triple(o,x,y);
		}
		else
		{
			vis[x]=true;
			Q[i]=Triple(o,x);
		}
	}
	for (int i=1;i<=k;i++) if (!vis[i]) Merge(a[i]);
	for (int i=m;i;i--)
	{
		if (Q[i].x) Merge(a[Q[i].y]);
		else ans[++ans[0]]=Query(Q[i].y,Q[i].z);
	}
	while (ans[0]) printf("%d\n",ans[ans[0]--]);
	return 0;
}