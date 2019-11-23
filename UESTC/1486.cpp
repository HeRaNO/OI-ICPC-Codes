#include <bits/stdc++.h>
#define MAXN 50005
#define MAXB 225
using namespace std;

int n,T,R,las,l,r,m,pos[MAXN],a[MAXN],c[MAXN],cnt[MAXB][MAXN],rev[MAXB][MAXN];
pair <int,int*> b[MAXN];

inline int lowbit(int x){return x&-x;}
inline void add(int x){for (;x<=R;x+=lowbit(x)) ++c[x];return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

inline void preWork()
{
	int C=pos[n];
	for (int i=1;i<=n;i++) ++cnt[pos[i]][a[i]];
	for (int i=1;i<=C;i++)
		for (int j=1;j<=R;j++)
			cnt[i][j]+=cnt[i][j-1];
	for (int i=1;i<=C;i++)
		for (int j=1;j<=R;j++)
			cnt[i][j]+=cnt[i-1][j];
	for (int i=1;i<=C;i++)
	{
		memset(c,0,sizeof c);
		for (int j=(i-1)*m+1,l=0;j<=n;j++,l++)
		{
			rev[i][j]=rev[i][j-1]+l-query(a[j]);
			add(a[j]);
		}
	}
	return ;
}

inline int query(int l,int r)
{
	if (l>r) swap(l,r);
	int ans=0;memset(c,0,sizeof c);
	if (pos[l]==pos[r])
	{
		for (int i=l,j=0;i<=r;i++,j++)
		{
			ans+=j-query(a[i]);
			add(a[i]);
		}
		return ans;
	}
	ans=rev[pos[l]+1][r];int pr=pos[r]-1,pl=pos[l];
	for (int i=(pos[r]-1)*m+1;i<=r;i++) add(a[i]);
	for (int i=pos[l]*m;i>=l;i--)
	{
		ans+=query(a[i]-1)+cnt[pr][a[i]-1]-cnt[pl][a[i]-1];
		add(a[i]);
	}
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
	read(n);m=(int)sqrt(n);
	for (int i=1;i<=n;i++)
	{
		read(a[i]);pos[i]=(i-1)/m+1;
		b[i]={a[i],&a[i]};
	}
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
	{
		if (b[i].first!=b[i-1].first) ++R;
		*b[i].second=R;
	}
	preWork();read(T);
	while (T--)
	{
		read(l);read(r);l^=las;r^=las;
		printf("%d\n",las=query(l,r));
	}
	return 0;
}