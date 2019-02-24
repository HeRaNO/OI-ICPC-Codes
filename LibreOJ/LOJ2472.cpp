#include <cstdio>
#include <algorithm>
#define MAXN 500010
using namespace std;

int tree[1<<20|1];
int n,k1,k2,k,l,t,d[MAXN],ans[MAXN],pt;
int sz[MAXN],cnt[MAXN],ch[MAXN];

inline int gcd(int a,int b){return !b?a:gcd(b,a%b);}

inline void modify(int x,int y)
{
	int l=1,r=n+1,m,u=1;
	while (l+1!=r)
	{
		tree[u]+=y;m=l+r>>1;
		if (x<m){u<<=1;r=m;}
		else{u=u<<1|1;l=m;}
	}
	tree[u]+=y;
	return ;
}

inline int query(int x)
{
	int l=1,r=n+1,m,u=1;
	while (l+1!=r)
	{
		m=l+r>>1;
		if (tree[u<<1|1]>=x){u=u<<1|1;l=m;}
		else{x-=tree[u<<1|1];u<<=1;r=m;}
	}
	return l;
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
	read(n);read(k1);read(k2);
	k=k1*1000+k2;l=1000;t=gcd(k,l);k/=t;l/=t;
	for (int i=1;i<=n;i++) ch[i*l/k]=i,read(d[i]);
	sort(d+1,d+n+1);
	for (int i=n;i;i--) 
	{
		sz[i*l/k]+=++sz[i];
		cnt[i]=d[i]==d[i+1]?cnt[i+1]+1:1;
	}
	for (int i=1;i<=ch[0];i++) modify(i,sz[i]);
	for (int i=1;i<=n;i++)
	{
		pt=query(cnt[i]);
		ans[pt]=d[i];modify(pt,-sz[pt]);
		for (int j=ch[pt-1]+1;j<=ch[pt];j++) modify(j,sz[j]);
	}
	for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}