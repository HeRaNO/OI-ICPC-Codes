#include <cstdio>
#include <algorithm>
#define MAXN 105
using namespace std;

int n,m,T,a[MAXN],ans;

inline void read(int &x)
{
	x=0;bool f=false;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	while (1)
	{
		read(n);if (!n) break;ans=0;
		for (int i=1;i<=n;i++) read(a[i]);
		m=(n>>1)+1;sort(a+1,a+n+1);
		for (int i=1;i<=m;i++) ans+=(a[i]>>1)+1;
		printf("%d\n",ans);
	}
	return 0;
}