#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int n,m,h,w,cnt,a[MAXN][MAXN],ans;
int sma[MAXN][MAXN],lar[MAXN][MAXN];
pair <int,pair<int,int> > b[MAXN*MAXN];

inline bool check(int x)
{
	memset(sma,0,sizeof sma);
	memset(lar,0,sizeof lar);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]<b[x].first) ++sma[i][j];
			if (a[i][j]>b[x].first) ++lar[i][j];
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			sma[i][j]+=sma[i][j-1];
			lar[i][j]+=lar[i][j-1];
		}
	for (int j=1;j<=m;j++)
		for (int i=1;i<=n;i++)
		{
			sma[i][j]+=sma[i-1][j];
			lar[i][j]+=lar[i-1][j];
		}
	for (int i=h;i<=n;i++)
		for (int j=w;j<=m;j++)
		{
			int sm=sma[i][j]-sma[i-h][j]-sma[i][j-w]+sma[i-h][j-w];
			int la=lar[i][j]-lar[i-h][j]-lar[i][j-w]+lar[i-h][j-w];
			if (sm==la)
			{
				ans=b[x].first;
				return true;
			}
			if (sm>la) return true;
		}
	return false;
}

int main()
{
	scanf("%d %d %d %d",&n,&m,&h,&w);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			b[++cnt]=make_pair(a[i][j],make_pair(i,j));
		}
	sort(b+1,b+n*m+1);
	int l=1,r=n*m;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
