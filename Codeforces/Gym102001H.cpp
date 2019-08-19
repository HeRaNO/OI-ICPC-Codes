#include <bits/stdc++.h>
#define fi first
#define se second
#define MAXN 100010
using namespace std;

struct H
{
	int l,r,p;
	bool operator < (const H &a)const{
		return r==a.r?l<a.l:r<a.r;
	}
};

H b[MAXN];
int n,k,c[MAXN],a[MAXN];
bool f[MAXN];

inline int lowbit(int x){return x&-x;}
inline void modify(int x,int v){for (;x<=n;x+=lowbit(x)) c[x]+=v;return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]) f[i]=true;
		else a[i]=-1;
		modify(i,a[i]);
	}
	for (int i=1;i<=k;i++)
		scanf("%d %d %d",&b[i].l,&b[i].r,&b[i].p);
	sort(b+1,b+k+1);
	bool no=false;
	for (int i=1;i<=k&&!no;i++)
	{
		int sum=query(b[i].r)-query(b[i].l-1);
		for (int j=b[i].r;j>=b[i].l&&sum<b[i].p;j--)
			if (!f[j])
			{
				modify(j,2);sum+=2;
				a[j]=1;
				f[j]=true;
			}
		if (sum<b[i].p) no=true;
	}
	if (no) return puts("Impossible"),0;
	for (int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}