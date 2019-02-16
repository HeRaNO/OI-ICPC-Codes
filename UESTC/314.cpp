#include <cstdio>
#define MAXN 100010
using namespace std;

int n,m,f[MAXN],x,y;

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main()
{
	scanf("%d %d",&n,&m);
	if (m!=n-1) return puts("false"),0;
	for (int i=1;i<n;i++) f[i]=i;
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);x=getf(x);y=getf(y);
		if (x!=y) f[x]=y;
	}
	for (int i=1;i<n;i++) if (getf(0)!=getf(i)) return puts("false"),0;
	puts("true");
	return 0;
}