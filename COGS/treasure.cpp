#include <cstdio>
#include <cstdio>
#define MAXN 110
#define MAXW 40010
using namespace std;

int n,W;
int v[MAXN],w[MAXN],m[MAXN];
long long dp[MAXW];
long long q1[MAXW],q2[MAXW];
int head1,tail1,head2,tail2;
int cnt;

int main()
{
	freopen("treasure.in","r",stdin);freopen("treasure.out","w",stdout);
	scanf("%d %d",&n,&W);
	for (int i=1;i<=n;i++) scanf("%d %d %d",&v[i],&w[i],&m[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<w[i];j++)
		{
			head1=tail1=0;head2=tail2=0;cnt=0;
			for (int k=j;k<=W;k+=w[i])
			{
				if (tail1-head1==m[i]+1)
				{
					if (q2[head2+1]==q1[head1+1]) head2++;
					head1++;
				}
				long long t=dp[k]-cnt*v[i];
				q1[++tail1]=t;
				while (head2<tail2&&q2[tail2]<t) tail2--;
				q2[++tail2]=t;
				dp[k]=q2[head2+1]+cnt*v[i];
				cnt++;
			}
		}
	}
	printf("%lld\n",dp[W]);
	return 0;
}