#include <bits/stdc++.h>
#define MAXN 55
using namespace std;

int n,m,a[MAXN][MAXN],b[MAXN][MAXN];
vector <pair<int,int> > ans;

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++)
			if (a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]==4)
			{
				b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
				ans.push_back(make_pair(i,j));
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]^b[i][j]) return puts("-1"),0;
	printf("%d\n",ans.size());
	for (auto i:ans) printf("%d %d\n",i.first,i.second);
	return 0;
}