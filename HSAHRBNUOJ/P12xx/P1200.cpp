#include <cstdio>
#define MAXN 2005
using namespace std;

int x[MAXN],y[MAXN],n,xx,yy;
long long d,ans=~(1LL<<63);

long long dis(int a,int b)
{
	long long m=x[a]-x[b],n=y[a]-y[b];return m*m+n*n;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			d=dis(i,j);
			if (ans>d)
			{
				ans=d;xx=i;yy=j;
			}
		}
	printf("%d %d\n",xx,yy);
	return 0;
}