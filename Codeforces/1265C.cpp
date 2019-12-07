#include <bits/stdc++.h>
#define MAXN 400005
using namespace std;

int T,n,a[MAXN],ans;
vector <int> v;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);ans=0;v.clear();
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) if (a[i]!=a[i+1]) v.push_back(i);
		for (auto i:v) if ((i<<1)<=n) ans=i;
		if (!ans){puts("0 0 0");continue;}
		int g=v[0],s,b;
		if (ans<g*3){puts("0 0 0");continue;}
		for (auto i:v) if(i>g*2) {s=i-g;break;}
		if (ans>g*2+s) printf("%d %d %d\n",g,s,ans-s-g);
		else puts("0 0 0");
	}
	return 0;
}