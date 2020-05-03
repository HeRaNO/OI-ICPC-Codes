#include <cstdio>
#define MAXN 500010
using namespace std;

int a[MAXN],b[MAXN];
int n;
long long ans;

void merge(int left,int middle,int right)
{
	int i=left,j=middle+1,k=left;
	while (i<=middle&&j<=right)
	{
		if (a[i]<=a[j]) b[k++]=a[i++];
		else
		{
			ans=ans+j-k;
			b[k++]=a[j++];
		}
	}
	while (i<=middle) b[k++]=a[i++];
	while (j<=right) b[k++]=a[j++];
	for (int i=left;i<=right;i++) a[i]=b[i];
}

void work(int l,int r)
{
	if (l<r)
	{
		int mid=(l+r)>>1;
		work(l,mid);
		work(mid+1,r);
		merge(l,mid,r);
	}
}

int main()
{
	freopen("sop.in","r",stdin);freopen("sop.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	work(1,n);
	printf("%lld\n",ans);
	return 0;
}