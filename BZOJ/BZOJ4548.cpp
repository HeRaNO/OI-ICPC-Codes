#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct Candy
{
	int x,y,c,id;
};

Candy a[MAXN];
pair<int,int*> b[MAXN];
int T,n,k,m,ans,l[MAXN],r[MAXN],las[MAXN],c[MAXN],d[MAXN];

inline int lowbit(int x){return x&-x;}
inline void modify(int x,int v){for (;x<=n+1;x+=lowbit(x)) c[x]+=v;return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}
inline void add(int l,int r)
{
	if (l>r) return ;
	ans=max(query(r)-query(l-1),ans);
	return ;
}

bool cmpx(Candy a,Candy b){return a.x<b.x;}
bool cmpy(Candy a,Candy b){return a.y<b.y;}

inline void Pick()
{
	d[0]=0;d[n+1]=n+1;
	memset(las,0,sizeof las);memset(c,0,sizeof c);
	sort(a+1,a+n+1,cmpx);
	for (int i=1;i<=n;i++) modify(a[i].x,1);
	for (int i=1;i<=n;i++)
	{
		int t=a[i].id,pc=las[a[i].c];
		l[t]=pc;r[t]=n+1;
		if (pc) r[pc]=t;
		add(d[pc]+1,d[t]-1);
		las[a[i].c]=t;
	}
	for (int i=1;i<=k;i++) add(d[las[i]]+1,n+1);
	sort(a+1,a+n+1,cmpy);
	for (int i=1,j=1;i<=n;i++)
	{
		int t=a[i].id;
		while (j<=n&&a[i].y==a[j].y) modify(a[j].x,-1),++j;
		l[r[t]]=l[t];r[l[t]]=r[t];
		add(d[l[t]]+1,d[r[t]]-1);
	}
	return ;
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
	read(T);
	while (T--)
	{
		read(n);read(k);ans=0;m=0;
		for (int i=1;i<=n;i++)
		{
			read(a[i].x);read(a[i].y);read(a[i].c);a[i].id=i;
			b[i]=make_pair(a[i].x,&a[i].x);
		}
		sort(b+1,b+n+1);
		for (int i=1;i<=n;i++)
		{
			if (b[i].first!=b[i-1].first) ++m;
			*b[i].second=m;
		}
		for (int i=1;i<=n;i++) d[i]=a[i].x;
		Pick();
		for (int i=1;i<=n;i++) a[i].y=-a[i].y;
		Pick();
		printf("%d\n",ans);
	}
	return 0;
}