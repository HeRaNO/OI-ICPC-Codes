#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct E
{
	int f;
	vector <int> a,b;
	E(){}
	E(int _,int __):f(_){
		a.clear();b.clear();
		a.push_back(__);
	}
};

E a[MAXN];
int T,n,cnt,rt,cas,x;

void add(int p,int x)
{
	vector <int> ta,tb;
	if (a[p].a.size()==3)
	{
		int f=a[p].f;
		swap(ta,a[p].a);swap(tb,a[p].b);
		if (p==rt)
		{
			a[rt=++cnt]=E(0,ta[1]);
			a[++cnt]=E(rt,ta[0]);
			a[p]=E(rt,ta[2]);
			a[rt].b.push_back(cnt);a[rt].b.push_back(p);
			if(tb.size())
			{
				a[cnt].b.push_back(tb[0]),a[tb[0]].f=cnt;
				a[cnt].b.push_back(tb[1]),a[tb[1]].f=cnt;
				a[p].b.push_back(tb[2]),a[tb[2]].f=p;
				a[p].b.push_back(tb[3]),a[tb[3]].f=p;
			}
			p=rt;
		}
		else
		{
			a[p]=E(f,ta[0]);
			a[++cnt]=E(f,ta[2]);
			a[f].a.push_back(ta[1]);
			sort(a[f].a.begin(),a[f].a.end());
			a[f].b.push_back(cnt);
			for(int i=a[f].b.size()-1;i>1;i--)
			{
				if (a[f].b[i-1]!=p) swap(a[f].b[i-1],a[f].b[i]);
				else break;
			}
			if(tb.size())
			{
				a[p].b.push_back(tb[0]),a[tb[0]].f=p;
				a[p].b.push_back(tb[1]),a[tb[1]].f=p;
				a[cnt].b.push_back((tb[2])),a[tb[2]].f=cnt;
				a[cnt].b.push_back(tb[3]),a[tb[3]].f=cnt;
			}
			p=f;
		}
	}
	if (a[p].b.size()==0)
	{
		a[p].a.push_back(x);
		sort(a[p].a.begin(),a[p].a.end());
	}
	else
	{
		if (x<a[p].a[0]) add(a[p].b[0],x);
		else if (x>a[p].a[a[p].a.size()-1]) add(a[p].b[a[p].b.size()-1],x);
		else
		{
			for (int i=1;i<a[p].a.size();i++)
				if (x<a[p].a[i]){add(a[p].b[i],x);break;}
		}
	}
	return ;
}

void dfs(int p)
{
	for (int i=0;i<a[p].a.size();i++)
		printf("%d%c",a[p].a[i],i==a[p].a.size()-1?'\n':' ');
	for (int i=0;i<a[p].b.size();i++) dfs(a[p].b[i]);
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%d",&x);
		rt=cnt=1;a[1]=E(0,x);
		for (int i=2;i<=n;i++) scanf("%d",&x),add(rt,x);
		printf("Case #%d:\n",++cas);
		dfs(rt);
	}
	return 0;
}