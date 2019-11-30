#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct D
{
	int l,r,d;
	bool operator < (const D &a)const{
		return r<a.l;
	}
};

D b[MAXN];
int n,m,k,t,a[MAXN];
set <D> s;
set <D> :: iterator it;

inline bool check(int x)
{
	int v=a[x];s.clear();
	for (int i=1;i<=k;i++)
	{
		if (b[i].d<=v) continue;
		it=s.find(b[i]);
		if (it==s.end()) s.insert(b[i]);
		else
		{
			D t=b[i];
			while ((it=s.find(t))!=s.end())
			{
				t.l=min(t.l,it->l);t.r=max(t.r,it->r);
				s.erase(it);
			}
			s.insert(t);
		}
	}
	int ans=n+1;
	for (auto it:s)
	{
		ans+=((it.r-it.l)<<1);
		if (ans>t) return false;
	}
	return true;
}

int main()
{
	scanf("%d %d %d %d",&m,&n,&k,&t);a[0]=~(1<<31);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	sort(a+1,a+m+1,greater<int>());
	for (int i=1;i<=k;i++)
	{
		scanf("%d %d %d",&b[i].l,&b[i].r,&b[i].d);
		++b[i].r;
	}
	int l=0,r=m,ans=0;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}