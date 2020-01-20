#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct Buildings
{
	int w,s;
	bool operator < (const Buildings &a)const{
		return w+s<a.w+a.s;
	}
}a[MAXN];

int n;
long long s[MAXN],pdv[MAXN];

int main()
{
	while (scanf("%d",&n)==1)
	{
		for (int i=1;i<=n;i++) scanf("%d %d",&a[i].w,&a[i].s);
		sort(a+1,a+n+1);int mx=0;
		for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i].w;
		for (int i=2;i<=n;i++) pdv[i]=s[i-1]-a[i].s;
		for (int i=1;i<=n;i++) if (pdv[mx]<pdv[i]) mx=i;
		printf("%lld\n",pdv[mx]);
	}
	return 0;
}