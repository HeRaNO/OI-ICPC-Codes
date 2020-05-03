#include <cstdio>
#define MAXN 200010
using namespace std;

int n,dis[MAXN];
int sum_dis,ans;

int myabs(int a)
{
	return a>0?a:-a;
}

int mymax(int a,int b)
{
	return a>b?a:b;
}

int binary(int l,int r,int q)
{
	if (l>=r) return q-dis[l];
	int middle=(l+r)>>1;
	if (q-dis[middle]<=sum_dis/2) return binary(l,middle,q);
	else return binary(middle+1,r,q);
}

int main()
{
	freopen("circlea.in","r",stdin);freopen("circlea.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&dis[i]);
		sum_dis+=dis[i];
		dis[i]+=dis[i-1];
	}
	for (int i=1;i<=n;i++) dis[i+n]=dis[i]+sum_dis;
	for (int i=1;i<=2*n;i++)
	{
		int res=myabs(sum_dis/2-binary(1,i-1,dis[i]));
		ans=mymax(ans,sum_dis/2-res);
	}
	printf("%d\n",ans);
	return 0;
}