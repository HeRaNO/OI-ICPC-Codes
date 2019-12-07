#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

vector <int> e[MAXN];
int n,u,v,a[MAXN];
double vl[MAXN],vr[MAXN],l,r=2e6,m;
bool p[MAXN],f[MAXN];
char s[3];

bool TreeDP(int x,int fa)
{
	f[x]=p[x];vl[x]=f[x]?0:a[x];vr[x]=f[x]?1e18:a[x];
	for (auto v:e[x])
		if (v!=fa)
		{
			if (!TreeDP(v,x)) return false;
			if (!f[v])
			{
				if (f[x])
				{
					f[x]=false;
					vl[x]=vl[v]-m;vr[x]=vr[v]+m;
				}
				else
				{
					vl[x]=max(vl[x],vl[v]-m);
					vr[x]=min(vr[x],vr[v]+m);
				}
			}
		}
	return f[x]||vl[x]<=vr[x];
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		if (!scanf("%d",&a[i]))
		{
			scanf("%s",s);p[i]=true;
		}
	for (int i=1;i<n;i++) scanf("%d %d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	for (int i=1;i<=50;i++)
	{
		m=(l+r)/2.0;
		if (TreeDP(1,-1)) r=m;
		else l=m;
	}
	printf("%.8lf\n",r);
	return 0;
}