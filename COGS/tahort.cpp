#include <cstdio>
#include <cstdlib>
#define MAXN 100010
using namespace std;

int h[MAXN],n,ans;

int mymax(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	freopen("tahort.in","r",stdin);freopen("tahort.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]);
	for (int j=n;j>1;j--) //right
		for (int i=j-1;i;i--) //left
		{
			if (h[i]>=h[j]) break;
			bool flag=true;
			for (int k=i+1;k<j;k++)
				if (h[k]<=h[i]||h[k]>=h[j])
				{
					flag=false;
					break;
				}
			if (flag) ans=mymax(ans,j-i+1);
			if (ans==n)
			{
				printf("%d\n",n);
				exit(0);
			}
		}
	printf("%d\n",ans);
	return 0;
}