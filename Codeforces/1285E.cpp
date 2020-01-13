#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct E
{
	int x,r,p;
	E(){}
	E(int _x,int _r,int _p):x(_x),r(_r),p(_p){}
	bool operator < (const E &a)const{
		return x==a.x?r<a.r:x<a.x;
	}
}p[MAXN];

set <int> s;
map <int,int> mp;
int n,cnt,mx,l[MAXN],r[MAXN],x[MAXN],y[MAXN],ans[MAXN];
vector <E> a;

inline void solve()
{
	scanf("%d",&n);cnt=1;mx=0;ans[0]=1<<31;
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&p[i].x,&p[i].r);p[i].p=i;
		a.push_back(E(p[i].x,-1,i));
		a.push_back(E(p[i].r,1,i));
	}
	sort(a.begin(),a.end());
	sort(p+1,p+n+1);
	int pl=p[1].x,pr=p[1].r;
	for (int i=2;i<=n;i++)
	{
		if (p[i].x>pr)
		{
			mp.insert({pl,0});++cnt;
			pl=p[i].x;pr=p[i].r;
		}
		else pr=max(pr,p[i].r);
	}
	mp.insert({pl,0});
	for (int i=0,p=n<<1;i<p;i++)
	{
		x[0]=y[0]=0;int j;
		for (j=i-1;j+1<p&&a[j+1].x==a[i].x;j++)
			if (~a[j+1].r) y[++y[0]]=a[j+1].p;
			else x[++x[0]]=a[j+1].p;
		i=j;
		if (s.size()==1&&x[0]) ++ans[*s.begin()];
		for (int j=1;j<=x[0];j++) s.insert(x[j]);
		for (int j=1;j<=y[0];j++) s.erase(y[j]);
	}
	for (int i=1;i<=n;i++) if (mp.count(p[i].x)) ++mp[p[i].x];
	for (int i=1;i<=n;i++) if (mp[p[i].x]==1) --ans[p[i].p];
	for (int i=1;i<=n;i++) if (ans[i]>ans[mx]) mx=i;
	printf("%d\n",ans[mx]+cnt);
	a.clear();s.clear();mp.clear();
	memset(ans,0,(n+1)<<2);
	return ;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}