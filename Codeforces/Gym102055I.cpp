#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,x[MAXN],y[MAXN],X,Y;
vector <pair<int,int*> > s,t;
int cntX[MAXN],cntY[MAXN];

inline void Solve()
{
	memset(cntX,0,sizeof cntX);memset(cntY,0,sizeof cntY);
	int ans=0,cnt=0;X=0;Y=0;s.clear();t.clear();
	s.push_back({-1,NULL});t.push_back({-1,NULL});
	for (int i=1;i<=n;i++)
	{
		s.push_back({x[i],&x[i]});
		t.push_back({y[i],&y[i]});
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
	if (X==1||Y==1){printf("1 %d\n",n);return ;}
	int mxx=0,mxy=0;
	for (int i=1;i<=n;i++)
	{
		++cntX[x[i]];++cntY[y[i]];
		mxx=max(cntX[x[i]],mxx);
		mxy=max(cntY[y[i]],mxy);
	}
	if (mxx==1&&mxy==1){printf("2 %lld\n",1LL*n*(n-1)/2);return ;}
	int xmx=0,xsmx=0,ymx=0,ysmx=0;
	for (int i=1;i<=X;i++)
	{
		if (cntX[i]==mxx) ++xmx;
		else if (cntX[i]==mxx-1) ++xsmx;
	}
	for (int i=1;i<=Y;i++)
	{
		if (cntY[i]==mxy) ++ymx;
		else if (cntY[i]==mxy-1) ++ysmx;
	}
	long long ans1=1LL*xmx*ymx;
	long long ans2=1LL*xmx*ysmx+1LL*xsmx*ymx;
	for (int i=1;i<=n;i++)
	{
		if (cntX[x[i]]+cntY[y[i]]==mxx+mxy)
		{
			--ans1;++ans2;
		}
		else if (cntX[x[i]]+cntY[y[i]]==mxx+mxy-1) --ans2;
	}
	if (!ans1) printf("%d %lld\n",mxx+mxy-1,ans2);
	else printf("%d %lld\n",mxx+mxy,ans1);
	return ;
}

int main()
{
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		printf("Case %d: ",cas);
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
		Solve();
	}
	return 0;
}