#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

const int M=1e9+7;

struct point
{
	int x,y;
	point(){}
	point(int _x,int _y):x(_x),y(_y){}
	bool operator < (const point &a)const{
		return y==a.y?x<a.x:y<a.y;
	}
};

point p[MAXN];
int n,mX,mY,ans,a[MAXN],down[MAXN],le[MAXN],ri[MAXN];
vector <pair<int,int*> > X,Y;
vector <int> L[MAXN];

inline void Solve()
{
	memset(a,0,sizeof a);memset(down,0,sizeof down);
	scanf("%d",&n);X.clear();Y.clear();mX=mY=ans=0;
	X.push_back({-10000,NULL});Y.push_back({-10000,NULL});
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
		X.push_back({p[i].x,&p[i].x});
		Y.push_back({p[i].y,&p[i].y});
	}
	sort(X.begin(),X.end());sort(Y.begin(),Y.end());
	for (int i=1;i<=n;i++)
	{
		if (X[i].first!=X[i-1].first) ++mX;
		*X[i].second=mX;
	}
	for (int i=1;i<=n;i++)
	{
		if (Y[i].first!=Y[i-1].first) ++mY;
		*Y[i].second=mY;
	}
	for (int i=1;i<=mY;i++) L[i].resize(0);
	sort(p+1,p+n+1);
	for (int i=1;i<=n;i++) L[p[i].y].push_back(p[i].x);
	for (int i=1;i<=mY;i++)
	{
		if (L[i].size()>=2)
		{
			int sL=L[i].size();
			for (int x=1;x<=mX;x++) down[x]=down[x-1]+a[x];
			for (int i=1;i<=n;i++) le[i]=ri[i]=0;
			for (int lx:L[i])
				for (int k=1;k<=n;k++)
					if (p[k].y>i&&lx<p[k].x)
						le[k]+=down[p[k].x-1]-down[lx];
			for (int rx:L[i])
				for (int k=1;k<=n;k++)
					if (p[k].y>i&&p[k].x<rx)
						ri[k]+=down[rx-1]-down[p[k].x];
			for (int k=1;k<=n;k++) (ans+=1LL*le[k]*ri[k]%M)%=M;
		}
		for (int x:L[i]) ++a[x];
	}
	printf("%d\n",ans);
	return ;
}

int main()
{
	int TT;scanf("%d",&TT);
	while (TT--) Solve();
	return 0;
}