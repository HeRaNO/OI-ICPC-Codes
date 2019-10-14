#include <bits/stdc++.h>
#define MAXN 50005
#define MAXQ 100005
using namespace std;

int pos[MAXN];

struct C
{
	int l,r,id;
	C(){}
	C(int _,int __,int ___):l(_),r(__),id(___){}
	bool operator < (const C &a)const{
		return pos[l]==pos[a.l]?r<a.r:pos[l]<pos[a.l];
	}
};

struct tri
{
	int x,y,z;
	tri(){}
	tri(int _,int __,int ___):x(_),y(__),z(___){}
	bool operator < (const tri &a)const{
		return y<a.y;
	}
	bool operator > (const tri &a)const{
		return x>a.x;
	}
};

C a[MAXQ];
tri el[MAXN],er[MAXN];
int T,n,m,q,b,x,y,top;
int l[MAXN],r[MAXN],f[MAXN],siz[MAXN],sta[MAXN],cnt[MAXN][2];
long long ans[MAXQ],res;

inline int getf(int x){return x==f[x]?x:getf(f[x]);}

inline void undo()
{
	while (top)
	{
		int u=sta[top--];
		siz[f[u]]-=siz[u];
		res-=1LL*siz[f[u]]*siz[u];
		f[u]=u;
	}
	return ;
}

inline void U(int x,int y,bool fl=true)
{
	x=getf(x);y=getf(y);
	if (x==y) return ;
	if (siz[x]<siz[y]) swap(x,y);
	f[y]=x;res+=1LL*siz[x]*siz[y];siz[x]+=siz[y];
	if (fl) sta[++top]=y;
	return ;
}

inline int clean(int x)
{
	memset(cnt,0,sizeof cnt);res=0;top=0;int i;
	for (i=1;i<=n;i++) f[i]=i,siz[i]=1;
	for (i=1;i<=m&&i<=x;i++) ++cnt[el[i].z][0];
	return i;
}

inline void Modui()
{
	int l,r;
	memset(cnt,0,sizeof cnt);res=0;top=0;
	for (int i=1;i<=n;i++) f[i]=i,siz[i]=1;
	for (int i=1,p;i<=q;i++)
	{
		if (pos[a[i].l]!=pos[a[i-1].l]){l=p=clean(pos[a[i-1].l]*b);r=1;}
		while (r<=m&&r<=a[i].r)
		{
			if (++cnt[er[r].z][1]==1&&cnt[er[r].z][0])
				U(er[r].x,er[r].y,false);
			++r;
		}
		long long t=res;
		while (l<=m&&l<=a[i].l)
		{
			if (++cnt[el[l].z][0]==1&&cnt[el[l].z][1])
				U(el[l].x,el[l].y);
			++l;
		}
		while (l>p) --cnt[el[--l].z][0];
		ans[a[i].id]=res;undo();res=t;
	}
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(T);pos[0]=-1;
	while (T--)
	{
		read(n);read(m);read(q);b=(int)sqrt(m);
		for (int i=1;i<=m;i++)
		{
			read(x);read(y);if (x>y) swap(x,y);
			el[i]=er[i]=tri(x,y,i);
			pos[i]=(i-1)/b+1;
		}
		sort(el+1,el+m+1,greater<tri>());
		sort(er+1,er+m+1);
		for (int i=n,pt=0;i;i--)
		{
			while (pt<m&&el[pt+1].x>=i) ++pt;
			l[i]=pt;
		}
		for (int i=1,pt=0;i<=n;i++)
		{
			while (pt<m&&er[pt+1].y<=i) ++pt;
			r[i]=pt;
		}
		for (int i=1;i<=q;i++)
		{
			read(x);read(y);
			a[i]=C(l[x],r[y],i);
		}
		sort(a+1,a+q+1);
		Modui();
		for (int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	}
	return 0;
}
