#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MAXQ 1300
#define MAXB 78
using namespace std;

struct seq
{
	long long a,b;int id;
	bool operator < (const seq &p)const{
		return b==p.b?a<p.a:b<p.b;
	}
};

seq a[MAXN],b[MAXB],bk[MAXB];
long long sta[MAXQ][MAXB][2],d[MAXQ];
int n,m,T,l,r,x,o,pos[MAXN],c,tp[MAXQ],p[MAXN],pmx[MAXQ];

inline int min(int a,int b){return a<b?a:b;}
inline void max(long long &a,long long b){if (a<b) a=b;return ;}

inline void Adjust(int x)
{
	int l=(x-1)*c+1,r=min(x*c,n);tp[x]=0;
	for (int i=l;i<=r;i++)
	{
		p[a[i].id]=i;
		while (tp[x]>1&&(a[i].a*a[i].b-sta[x][tp[x]][0])*(sta[x][tp[x]][1]-sta[x][tp[x]-1][1])
						>=(sta[x][tp[x]][0]-sta[x][tp[x]-1][0])*(a[i].b-sta[x][tp[x]][1])) --tp[x];
		sta[x][++tp[x]][0]=a[i].a*a[i].b;
		sta[x][  tp[x]][1]=a[i].b;
	}
	for (pmx[x]=1;pmx[x]<tp[x]&&sta[x][pmx[x]+1][0]>=sta[x][pmx[x]][0];++pmx[x]);
	return ;
}

inline void clean(int x,int ll=0,int rr=0,long long delta=0LL)
{
	int l=(x-1)*c+1,r=min(x*c,n);
	if (!ll&&!rr) sort(a+l,a+r+1);
	else
	{
		long long m=d[x];int lb=0,lbk=0;d[x]=0LL;
		for (int i=l;i<=r;i++)
		{
			a[i].a+=m;
			if (a[i].id<ll||a[i].id>rr) bk[++lbk]=a[i];
			else b[++lb]=a[i],b[lb].a+=delta;
		}
		int i=1,j=1,k=l;
		while (i<=lb&&j<=lbk)
		{
			if (b[i]<bk[j]) a[k++]=b[i++];
			else a[k++]=bk[j++];
		}
		while (i<=lb)  a[k++]=b[i++];
		while (j<=lbk) a[k++]=bk[j++];
	}
	Adjust(x);
	return ;
}

inline void A(int l,int r,long long x)
{
	if (pos[l]==pos[r])
	{
		clean(pos[l],l,r,x);
		return ;
	}
	clean(pos[l],l,pos[l]*c,x);
	for (int i=pos[l]+1;i<pos[r];i++)
	{
		d[i]+=x;
		for (;pmx[i]<tp[i]&&sta[i][pmx[i]+1][0]+d[i]*sta[i][pmx[i]+1][1]>=
							  sta[i][pmx[i]][0]+d[i]*sta[i][pmx[i]][1];++pmx[i]);
	}
	clean(pos[r],(pos[r]-1)*c+1,r,x);
	return ;
}

inline void B(int l,int r)
{
	int pt;
	if (pos[l]==pos[r])
	{
		long long m=d[pos[l]];d[pos[l]]=0LL;
		int ll=(pos[l]-1)*c+1,rr=pos[l]*c,lb=0,lbk=0;
		for (int i=ll;i<=rr;i++)
		{
			a[i].a+=m;
			if (a[i].id==l||a[i].id==r) bk[++lbk]=a[i];
			else b[++lb]=a[i];
		}
		swap(bk[1].b,bk[2].b);if (!(bk[1]<bk[2])) swap(bk[1],bk[2]);
		int i=1,j=1,k=ll;
		while (i<=lb&&j<=lbk)
		{
			if (b[i]<bk[j]) a[k++]=b[i++];
			else a[k++]=bk[j++];
		}
		while (i<=lb)  a[k++]=b[i++];
		while (j<=lbk) a[k++]=bk[j++];
		Adjust(pos[l]);return ;
	}
	swap(a[p[l]].b,a[p[r]].b);
	int pl=(pos[l]-1)*c+1,pr=pos[l]*c;long long m=d[pos[l]];
	for (int i=pl;i<=pr&&i<=n;i++) a[i].a+=m;d[pos[l]]=0LL;
	pl=(pos[r]-1)*c+1;pr=pos[r]*c;m=d[pos[r]];
	for (int i=pl;i<=pr&&i<=n;i++) a[i].a+=m;d[pos[r]]=0LL;
	for (pt=p[l];!(a[pt]<a[pt+1])&&pt<pos[l]*c;swap(a[pt],a[pt+1]),++pt);
	for (;!(a[pt-1]<a[pt])&&pt>(pos[l]-1)*c+1;swap(a[pt],a[pt-1]),--pt);
	for (pt=p[r];!(a[pt]<a[pt+1])&&pt<pos[r]*c;swap(a[pt],a[pt+1]),++pt);
	for (;!(a[pt-1]<a[pt])&&pt>(pos[r]-1)*c+1;swap(a[pt],a[pt-1]),--pt);
	Adjust(pos[l]);Adjust(pos[r]);
	return ;
}

inline long long C(int l,int r)
{
	long long ans=0;int pt=pos[l];
	if (pos[l]==pos[r])
	{
		int ll=(pos[l]-1)*c+1,rr=pos[l]*c;
		for (int i=ll;i<=rr&&i<=n;i++) if (a[i].id>=l&&a[i].id<=r) max(ans,(a[i].a+d[pt])*a[i].b);
		return ans;
	}
	for (int i=(pos[l]-1)*c+1,t=pos[l]*c;i<=t;i++)
		if (a[i].id>=l)
			max(ans,(a[i].a+d[pt])*a[i].b);
	pt=pos[r];
	for (int i=(pos[r]-1)*c+1,t=pos[r]*c;i<=t&&i<=n;i++)
		if (a[i].id<=r)
			max(ans,(a[i].a+d[pt])*a[i].b);
	for (int i=pos[l]+1;i<pos[r];i++) max(ans,sta[i][pmx[i]][0]+d[i]*sta[i][pmx[i]][1]);
	return ans;
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
	read(n);read(T);c=(int)sqrt(n/log2(n));
	for (int i=1;i<=n;i++) read(x),a[i].a=x,pos[i]=(i-1)/c+1;
	for (int i=1;i<=n;i++) read(x),a[i].b=x,a[i].id=i;
	for (int i=1;i<=pos[n];i++) clean(i);
	while (T--)
	{
		read(o);read(l);read(r);
		if (o==1) read(x),A(l,r,x);
		else if (o==2) B(l,r);
		else printf("%lld\n",C(l,r));
	}
	return 0;
}
