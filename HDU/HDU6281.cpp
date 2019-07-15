#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

struct tu
{
	__int128 a,b,c;int id;
	tu(){}
	tu(int x,int y,int z):a(x),b(y),c(z){}
	bool operator < (const tu &x)const{
		if ((a+b)*(x.a+x.b+x.c)==(x.a+x.b)*(a+b+c)) return id<x.id;
		return (a+b)*(x.a+x.b+x.c)<(x.a+x.b)*(a+b+c);
	}
};

tu p[MAXN];
int n,a,b,c;

int main()
{
	while (~scanf("%d",&n))
	{
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			p[i]=tu(a,b,c);
			p[i].id=i;
		}
		sort(p+1,p+n+1);
		for (int i=1;i<=n;i++) printf("%d%c",p[i].id,i==n?'\n':' ');
	}
	return 0;
}