#include <cstdio>
#include <algorithm>
using namespace std;

struct B
{
	long long x;int y;
	bool operator < (const B &a)const{
		if (x==a.x) return y<a.y;
		return x>a.x;
	}
};

int n,m,k,cnt,cc;
bool p[200010];long long s;
B a[200010];

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i].x),a[i].y=i;
	sort(a+1,a+n+1);
	for (int i=1;i<=m*k;i++) p[a[i].y]=true,s+=a[i].x;
	printf("%I64d\n",s);
	for (int i=1;i<=n;i++)
	{
		if (p[i]) ++cnt;
		if (cnt==m)
		{
			printf("%d ", i);
			cnt=0;++cc;
			if (cc==k-1) return 0;
		}
	}
	puts("");
	return 0;
}
