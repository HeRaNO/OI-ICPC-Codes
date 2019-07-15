#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct seg
{
	int l,r,x;
	seg(){}
	seg(int a,int b,int c):l(a),r(b),x(c){}
	bool operator < (const seg &a)const{
		if (r!=a.r) return r<a.r;
		if (x!=a.x) return x<a.x;
		return l<a.l;
	}
};

seg a[MAXN<<1];
int T,n,q,l,r,cnt,c[MAXN],ans[MAXN];

inline int lowbit(int x){return x&-x;}
inline void modify(int x){for (;x<=n;x+=lowbit(x)) ++c[x];return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(c,0,sizeof c);cnt=0;
		scanf("%d %d",&n,&q);
		for (int i=1;i<n+q;i++)
		{
			scanf("%d %d",&l,&r);
			if (l>r) swap(l,r);
			a[i]=seg(l,r,i);
		}
		sort(a+1,a+n+q);
		for (int i=1;i<n+q;i++)
		{
			if (a[i].x<n)
			{
				++cnt;modify(a[i].l);
			}
			else ans[a[i].x-n+1]=a[i].r-a[i].l+1-cnt+query(a[i].l-1);
		}
		for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
	return 0;
}