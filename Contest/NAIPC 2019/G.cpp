#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,X,Y,a[MAXN],b[MAXN],c[MAXN],d[MAXN],p[MAXN],_1x[MAXN],_2x[MAXN],_1y[MAXN];
vector <pair<int,int*> > s,t;
vector <pair<int,int> > v[MAXN],h[MAXN];
pair <int,int> q[MAXN];

inline int lowbit(int x){return x&-x;}
inline void modify(int x,int v){for (;x<=X;x+=lowbit(x)) p[x]+=v;return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=p[x];return r;}
inline int query(int l,int r){return query(r)-query(l-1);}

int main()
{
	scanf("%d",&n);
	s.push_back({1<<31,NULL});t.push_back({1<<31,NULL});
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
		s.push_back({a[i],&a[i]});s.push_back({c[i],&c[i]});
		t.push_back({b[i],&b[i]});t.push_back({d[i],&d[i]});
		s.push_back({a[i]+1,&_1x[i]});s.push_back({c[i]-1,&_2x[i]});
		t.push_back({d[i]+1,&_1y[i]});
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
		v[b[i]].push_back({a[i],1});v[b[i]].push_back({c[i],1});
		v[_1y[i]].push_back({a[i],-1});v[_1y[i]].push_back({c[i],-1});
		h[b[i]].push_back({_1x[i],_2x[i]});
		h[d[i]].push_back({_1x[i],_2x[i]});
	}
	for (int y=1;y<=Y;y++)
	{
		for (auto i:v[y]) modify(i.first,i.second);
		for (auto i:h[y]) if (query(i.first,i.second)) return puts("1"),0;
	}
	puts("0");
	return 0;
}