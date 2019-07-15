#include <bits/stdc++.h>
#define MAXN 10010
#define MAXM 20010
#define MAXQ 50010
using namespace std;

struct Query
{
	bool type;int x,y;
	Query(){}
	Query(bool a,int p,int q=0):type(a),x(p),y(q){}
};

Query a[MAXQ];
int n,m,q,p[MAXN],x,y,f[MAXN],ans[MAXQ];
bool des[MAXM],ff;
char o[15];
map <pair<int,int>,int> mp;
map <pair<int,int>,int> :: iterator it;
pair <int,int> v[MAXM];

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void merge(int x,int y)
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy) return ;
	if (p[fx]<p[fy]) f[fx]=fy;
	else if (p[fx]==p[fy])
	{
		if (fx<fy) f[fy]=fx;
		else f[fx]=fy;
	}
	else f[fy]=fx;
	return ;
}

int main()
{
	while (~scanf("%d",&n))
	{
		if (ff) puts("");
		mp.clear();memset(des,false,sizeof des);ans[0]=0;
		for (int i=0;i<n;i++) f[i]=i;
		for (int i=0;i<n;i++) scanf("%d",&p[i]);
		scanf("%d",&m);
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d",&x,&y);
			if (x>y) swap(x,y);
			mp.insert(make_pair(make_pair(x,y),i));
			v[i]=make_pair(x,y);
		}
		scanf("%d",&q);
		for (int i=1;i<=q;i++)
		{
			scanf("%s",o);
			if (o[0]=='d')
			{
				scanf("%d %d",&x,&y);
				a[i]=Query(false,min(x,y),max(x,y));
				it=mp.find(make_pair(min(x,y),max(x,y)));
				des[it->second]=true;
			}
			else
			{
				scanf("%d",&x);
				a[i]=Query(true,x);
			}
		}
		for (int i=1;i<=m;i++) if (!des[i]) merge(v[i].first,v[i].second);
		for (int i=q;i;i--)
		{
			if (a[i].type)
			{
				int fx=getf(a[i].x);
				ans[++ans[0]]=p[fx]<=p[a[i].x]?-1:fx;
			}
			else
			{
				merge(a[i].x,a[i].y);
			}
		}
		for (int i=ans[0];i;i--) printf("%d\n",ans[i]);
		ff=true;
	}
	return 0;
}