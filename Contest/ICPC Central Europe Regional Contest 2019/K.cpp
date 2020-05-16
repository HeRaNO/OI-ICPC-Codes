#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int mx[1<<19],mn[1<<19];
int n,m,a[MAXN],pre[MAXN],suf[MAXN],f[MAXN],g[MAXN],p[MAXN];
map <int,int> s;
pair <int,int*> b[MAXN];

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r){mx[u]=mn[u]=a[l];return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	mn[u]=min(mn[u<<1],mn[u<<1|1]);
	return ;
}

inline int qmin(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return mn[u];
	int m=pl+pr>>1;
	if (r<=m) return qmin(u<<1,l,r,pl,m);
	else if (m<=l) return qmin(u<<1|1,l,r,m,pr);
	else return min(qmin(u<<1,l,m,pl,m),qmin(u<<1|1,m,r,m,pr));
}

inline int qmax(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return mx[u];
	int m=pl+pr>>1;
	if (r<=m) return qmax(u<<1,l,r,pl,m);
	else if (m<=l) return qmax(u<<1|1,l,r,m,pr);
	else return max(qmax(u<<1,l,m,pl,m),qmax(u<<1|1,m,r,m,pr));
}

inline bool _111()
{
	for (int i=1;i<=n;i++)
	{
		s[a[i]]++;
		if (s[a[i]]==3) return true;
	}
	return false;
}

inline bool _112()
{
	s.clear();
	for (int i=1;i<=n;i++)
	{
		s[a[i]]++;
		if (s[a[i]]>=2&&qmax(1,i,n+1,1,n+1)>a[i]) return true;
	}
	return false;
}

inline bool _121()
{
	for (int i=1;i<=m;i++)
	{
		if (f[i]+1>=g[i]) continue;
		if (qmax(1,f[i]+1,g[i],1,n+1)>i) return true;
	}
	return false;
}

inline bool _122()
{
	s.clear();
	for (int i=n;i>=2;i--)
	{
		s[a[i]]++;
		if (s[a[i]]>=2&&qmin(1,1,i,1,n+1)<a[i]) return true;
	}
	return false;
}

inline bool _123()
{
	for (int i=2;i<n;i++)
		if (qmin(1,1,i,1,n+1)<a[i]&&qmax(1,i+1,n+1,1,n+1)>a[i])
			return true;
	return false;
}

inline bool _132()
{
	set <int> s;
	for (int i=n;i>=2;i--)
	{
		s.insert(a[i]);
		auto it=s.find(a[i]);
		if (it==s.begin()) continue;
		--it;
		if (qmin(1,1,i,1,n+1)<*it) return true;
	}
	return false;
}

inline bool _211()
{
	s.clear();
	for (int i=n;i>=2;i--)
	{
		s[a[i]]++;
		if (s[a[i]]>=2&&qmax(1,1,i,1,n+1)>a[i]) return true;
	}
	return false;
}

inline bool _212()
{
	for (int i=1;i<=m;i++)
	{
		if (f[i]+1>=g[i]) continue;
		if (qmin(1,f[i]+1,g[i],1,n+1)<i) return true;
	}
	return false;
}

inline bool _213()
{
	set <int> s;
	for (int i=1;i<n;i++)
	{
		s.insert(a[i]);
		auto it=s.find(a[i]);++it;
		if (it==s.end()) continue;
		if (qmax(1,i+1,n+1,1,n+1)>*it) return true;
	}
	return false;
}

inline bool _221()
{
	s.clear();
	for (int i=1;i<n;i++)
	{
		s[a[i]]++;
		if (s[a[i]]>=2&&qmin(1,i+1,n+1,1,n+1)<a[i]) return true;
	}
	return false;
}

inline bool _231()
{
	set <int> s;
	for (int i=1;i<n;i++)
	{
		s.insert(a[i]);
		auto it=s.find(a[i]);
		if (it==s.begin()) continue;
		--it;
		if (qmin(1,i+1,n+1,1,n+1)<*it) return true;
	}
	return false;
}

inline bool _312()
{
	set <int> s;
	for (int i=n;i>=2;i--)
	{
		s.insert(a[i]);
		auto it=s.find(a[i]);++it;
		if (it==s.end()) continue;
		if (qmax(1,1,i,1,n+1)>*it) return true;
	}
	return false;
}

inline bool _321()
{
	for (int i=2;i<n;i++)
		if (qmax(1,1,i,1,n+1)>a[i]&&qmin(1,i+1,n+1,1,n+1)<a[i])
			return true;
	return false;
}

int main()
{
	memset(f,0x3f,sizeof f);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]={a[i],&a[i]};
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
	{
		if (b[i].first!=b[i-1].first) ++m;
		*b[i].second=m;
	}
	for (int i=1;i<=n;i++) pre[i]=max(pre[i-1],a[i]);
	for (int i=n;i;i--) suf[i]=max(suf[i+1],a[i]);
	for (int i=1;i<=n;i++) f[a[i]]=min(f[a[i]],i),g[a[i]]=max(g[a[i]],i);
	BuildTree(1,1,n+1);
	if (_111()) puts("111");if (_112()) puts("112");
	if (_121()) puts("121");if (_122()) puts("122");
	if (_123()) puts("123");if (_132()) puts("132");
	if (_211()) puts("211");if (_212()) puts("212");
	if (_213()) puts("213");if (_221()) puts("221");
	if (_231()) puts("231");
	if (_312()) puts("312");if (_321()) puts("321");
	return 0;
}