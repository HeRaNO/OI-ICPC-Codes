#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,a,b,c,x,ans,cnt,p[MAXN],l[3],r[3];

int main()
{
	scanf("%d %d %d",&a,&b,&c);ans=a+b;n=a+b+c;
	for (int i=1;i<=a;i++) scanf("%d",&x),p[x]=0;
	for (int i=1;i<=b;i++) scanf("%d",&x),p[x]=1;
	for (int i=1;i<=c;i++) scanf("%d",&x),p[x]=2;
	for (int i=1;i<=n;i++) ++r[p[i]];
	for (int i=1;i<=n;i++)
	{
		++l[p[i]];--r[p[i]];
		cnt=max(cnt,l[0]-l[1]);
		ans=min(ans,r[0]+r[1]+l[0]+l[2]-cnt);
	}
	printf("%d\n",ans);
	return 0;
}