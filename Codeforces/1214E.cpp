#include <cstdio>
#include <algorithm>
#define MAXN 200005
using namespace std;

struct E
{
	int x,d;
	bool operator < (const E &a)const{
		return d>a.d;
	}
};

int n,m;
E a[MAXN];

int main()
{
	scanf("%d",&n);m=n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].d);
		a[i].x=(i<<1)-1;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++) printf("%d %d\n",a[i].x,a[i+1].x);
	for (int i=1;i<=n;i++)
	{
		printf("%d %d\n",a[i].x+1,a[i+a[i].d-1].x);
		if (i+a[i].d==m+1) a[++m].x=a[i].x+1;
	}
	return 0;
}