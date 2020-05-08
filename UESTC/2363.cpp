#include <bits/stdc++.h>
#define MAXN 1000005
#define MAXK 5000005
using namespace std;

const int W=2e6+1;

int n,pt=1000000,mx[MAXK],mn[MAXK],lazy[MAXK];
char s[MAXN],p[MAXN<<1];

inline void add(int u,int v)
{
	mx[u]+=v;mn[u]+=v;lazy[u]+=v;
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	add(u<<1,lazy[u]);add(u<<1|1,lazy[u]);lazy[u]=0;
	return ;
}

inline void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (pl==l&&pr==r){add(u,v);return ;}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	mn[u]=min(mn[u<<1],mn[u<<1|1]);
	return ;
}

inline int qmax(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return mx[u];
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) return qmax(u<<1,l,r,pl,m);
	else if (m<=l) return qmax(u<<1|1,l,r,m,pr);
	else return max(qmax(u<<1,l,m,pl,m),qmax(u<<1|1,m,r,m,pr));
}

inline int qmin(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return mn[u];
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) return qmin(u<<1,l,r,pl,m);
	else if (m<=l) return qmin(u<<1|1,l,r,m,pr);
	else return min(qmin(u<<1,l,m,pl,m),qmin(u<<1|1,m,r,m,pr));
}

int main()
{
	scanf("%d",&n);scanf("%s",s);
	for (int i=0;i<n;i++)
	{
		if (s[i]=='R') ++pt;
		else if (s[i]=='L') --pt;
		else if (s[i]=='(')
		{
			if (p[pt]!='(')
			{
				if (p[pt]==')') modify(1,pt,W,2,1,W);
				else modify(1,pt,W,1,1,W);
				p[pt]='(';
			}
		}
		else if (s[i]==')')
		{
			if (p[pt]!=')')
			{
				if (p[pt]=='(') modify(1,pt,W,-2,1,W);
				else modify(1,pt,W,-1,1,W);
				p[pt]=')';
			}
		}
		else
		{
			if (p[pt]=='(') modify(1,pt,W,-1,1,W);
			if (p[pt]==')') modify(1,pt,W,1,1,W);
			p[pt]=s[i];
		}
		if (mn[1]>=0&&qmin(1,W-1,W,1,W)==0)
			printf("%d%c",mx[1],i==n-1?'\n':' ');
		else printf("-1%c",i==n-1?'\n':' ');
	}
	return 0;
}