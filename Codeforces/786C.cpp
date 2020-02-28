#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,a[MAXN],ans[MAXN];
bool vis[MAXN];

inline int check(int x)
{
	int cnt=0,res=1,las=0;
	for (int i=1;i<=n;i++) vis[i]=false;
	for (int i=1;i<=n;i++)
		if (!vis[a[i]])
		{
			vis[a[i]]=true;++cnt;
			if (cnt>x)
			{
				++res;cnt=1;
				for (int j=las;j<i;j++) vis[a[j]]=false;
				las=i;
			}
		}
	return res;
}

inline void Solve(int l,int r)
{
	int p=check(l);
	if (p==check(r))
	{
		for (int i=l;i<=r;i++) ans[i]=p;
		return ;
	}
	int m=l+r>>1;
	Solve(l,m);Solve(m+1,r);
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	Solve(1,n);
	for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}