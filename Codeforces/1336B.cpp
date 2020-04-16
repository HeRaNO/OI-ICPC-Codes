#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n[3],a[3][MAXN];
vector <pair<long long,int> > p;
long long ans=~(1LL<<63);

inline long long f(long long x,long long y,long long z)
{
	return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
}

inline void Solve(int x,int y,int z)
{
	long long q[2];q[0]=q[1]=0;p.clear();
	for (int i=1;i<=n[x];i++) p.push_back({a[x][i],0});
	for (int i=1;i<=n[y];i++) p.push_back({a[y][i],1});
	sort(p.begin(),p.end());
	for (auto v:p)
	{
		q[v.second]=v.first;
		if (!q[0]||!q[1]) continue;
		long long t=q[0]+q[1];
		auto it=lower_bound(a[z]+1,a[z]+n[z]+1,t/2)-a[z];
		if (it<=n[z]) ans=min(ans,f(q[0],q[1],a[z][it]));
		if (it<n[z]) ans=min(ans,f(q[0],q[1],a[z][it+1]));
		if (it>=2) ans=min(ans,f(q[1],q[0],a[z][it-1]));
	}
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans=~(1LL<<63);
		scanf("%d %d %d",&n[0],&n[1],&n[2]);
		for (int i=0;i<=2;i++)
		{
			for (int j=1;j<=n[i];j++) scanf("%d",&a[i][j]);
			sort(a[i]+1,a[i]+n[i]+1);
		}
		Solve(0,1,2);
		Solve(0,2,1);
		Solve(1,0,2);
		printf("%lld\n",ans);
	}
	return 0;
}