#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,m,X,Y,a[MAXN],b[MAXN],c[MAXN],d[MAXN],p[MAXN<<1],_1y[MAXN];
long long ans[MAXN<<2];
vector <pair<int,int*> > s,t;
vector <pair<int,int> > v[MAXN<<2],h[MAXN<<2];
pair <int,int> q[MAXN];

inline int lowbit(int x){return x&-x;}
inline void modify(int x,int v){for (;x<=X;x+=lowbit(x)) p[x]+=v;return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=p[x];return r;}
inline int query(int l,int r){return query(r)-query(l-1);}

int main()
{
	scanf("%d %d",&n,&m);
	s.push_back({-1,NULL});t.push_back({-1,NULL});
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
		if (a[i]==c[i])
		{
			s.push_back({a[i],&a[i]});c[i]=0;
			t.push_back({b[i],&b[i]});
			t.push_back({d[i]+1,&_1y[i]});
		}
		else
		{
			s.push_back({a[i],&a[i]});
			s.push_back({c[i],&c[i]});
			t.push_back({b[i],&b[i]});
		}
	}
	for (int i=1,x,y;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		t.push_back({y,&q[i].second});
		t.push_back({x-1,&q[i].first});
	}
	sort(s.begin(),s.end());sort(t.begin(),t.end());
	for (int i=1;i<(int)s.size();i++)
	{
		if (s[i].first!=s[i-1].first) ++X;
		*s[i].second=X;
	}
	for (int i=1;i<(int)t.size();i++)
	{
		if (t[i].first!=t[i-1].first) ++Y;
		*t[i].second=Y;
	}
	for (int i=1;i<=n;i++)
	{
		if (!c[i])
		{
			v[b[i]].push_back({a[i],1});
			v[_1y[i]].push_back({a[i],-1});
		}
		else h[b[i]].push_back({a[i],c[i]});
	}
	for (int y=1;y<=Y;y++)
	{
		for (auto i:v[y]) modify(i.first,i.second);
		for (auto i:h[y]) ans[y]+=query(i.first,i.second);
	}
	for (int y=1;y<=Y;y++) ans[y]+=ans[y-1];
	for (int i=1;i<=m;i++)
		printf("%lld\n",ans[q[i].second]-ans[q[i].first]);
	return 0;
}