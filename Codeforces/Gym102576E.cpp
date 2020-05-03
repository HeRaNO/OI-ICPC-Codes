#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,m;
int x[MAXN],y[MAXN],r[MAXN],px[MAXN],qx[MAXN],ymn[MAXN],ymx[MAXN];
int mx[1<<22];
bool ans[MAXN];
vector <int> v;
vector <pair<int,int> > q;

inline void BuildTree(int u,int l,int r)
{
	mx[u]=1<<31;if (l+1==r) return ;
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	return ;
}

inline void modify(int u,int p,int v,int pl,int pr)
{
	if (pl+1==pr){mx[u]=max(mx[u],v);return ;}
	int m=pl+pr>>1;
	if (p<m) modify(u<<1,p,v,pl,m);
	else modify(u<<1|1,p,v,m,pr);
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return mx[u];
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return max(query(u<<1,l,m,pl,m),query(u<<1|1,m,r,m,pr));
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d %d %d",&x[i],&y[i],&r[i]);
	for (int i=1,a,b;i<=m;i++)
	{
		scanf("%d %d %d %d %d %d",&px[i],&a,&qx[i],&b,&ymn[i],&ymx[i]);
		if (px[i]>qx[i]) swap(px[i],qx[i]);
		v.push_back(px[i]-1);v.push_back(qx[i]);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	int R=v.size();
	BuildTree(1,1,R+1);
	for (int i=1;i<=n;i++)
	{
		q.push_back({y[i]-r[i],-i});
		x[i]=lower_bound(v.begin(),v.end(),x[i])-v.begin()+1;
	}
	for (int i=1;i<=m;i++)
	{
		q.push_back({ymn[i],i});
		px[i]=lower_bound(v.begin(),v.end(),px[i]-1)-v.begin()+1;
		qx[i]=lower_bound(v.begin(),v.end(),qx[i])-v.begin()+1;
	}
	sort(q.begin(),q.end());
	for (auto now:q)
	{
		int v=now.second;
		if (v<0)
		{
			v=-v;
			if (x[v]<=R) modify(1,x[v],y[v]+r[v],1,R+1);
		}
		else ans[v]=query(1,px[v]+1,qx[v]+1,1,R+1)<ymx[v];
	}
	for (int i=1;i<=m;i++) puts(ans[i]?"YES":"NO");
	return 0;
}