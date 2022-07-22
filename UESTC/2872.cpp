#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct Fa
{
	int a,b;
	Fa():a(0),b(0){}
	Fa(int _a,int _b):a(_a),b(_b){}
	void Raise(){++a;return ;}
	void Down(){a=0;b=1;return ;}
	Fa operator + (const Fa &y)const{
		return Fa(y.b?y.a:a+y.a,b|y.b);
	}
};

Fa a[MAXN],s[MAXN];
int n,m,id[MAXN],q[MAXN],nxt[MAXN];
bool vis[MAXN];
long long ans[MAXN];
vector<vector<int>> cy;

int safeIndex(int x,int m){return x>=m?x-m:x;}

void dfs(int x,vector<int> &c)
{
	if (vis[x]) return ;
	vis[x]=true;c.push_back(x);dfs(nxt[x],c);
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) id[i]=i;
	for (int i=1;i<=m;i++)
	{
		char opt[3];int x,y;
		scanf("%s",opt);
		if (opt[0]=='+')
		{
			scanf("%d",&x);
			a[x].Raise();
		}
		else if (opt[0]=='E')
		{
			scanf("%d",&x);
			a[x].Down();
		}
		else
		{
			scanf("%d %d",&x,&y);
			swap(a[x],a[y]);swap(id[x],id[y]);
		}
	}
	for (int i=1;i<=n;i++) nxt[id[i]]=i;
	for (int i=1;i<=n;i++) scanf("%d",&q[i]);
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			cy.push_back({});
			dfs(i,cy.back());
		}
	for (auto c:cy)
	{
		int m=c.size();
		for (int i=1;i<=m*2;i++)
			s[i]=s[i-1]+a[c[safeIndex(i-1,m)]];
		if (!s[m].b)
		{
			long long all=s[m].a;
			for (int i=0;i<m;i++)
			{
				int t=q[id[c[i]]]/m,p=q[id[c[i]]]%m;
				int r=i,l=i-p;
				if (l<0) l+=m,r+=m;
				ans[id[c[i]]]=all*t+s[r].a-s[l].a;
			}
		}
		else
		{
			int las=0;
			for (int i=m;i&&!las;i--) if (a[c[i-1]].b) las=i;
			las-=m;
			for (int i=1;i<=m;i++)
			{
				if (a[c[i-1]].b) las=i;
				int k=q[id[c[safeIndex(i,m)]]];
				if (i-k>=las) ans[id[c[safeIndex(i,m)]]]=s[i+m].a-s[i+m-k].a;
				else ans[id[c[safeIndex(i,m)]]]=s[i+m].a;
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%lld%c",ans[i]," \n"[i==n]);
	return 0;
}