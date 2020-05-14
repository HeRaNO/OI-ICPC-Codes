#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct data
{
	long long x,y,ans;
	data(){}
	data(long long _,long long __,long long ___):
		x(_),y(__),ans(___){}
	data operator + (const data &a)const{
		data res;
		res.x=max(x,a.x);res.y=max(y,a.y);
		res.ans=max(max(ans,a.ans),max(x+a.y,y+a.x));
		return res;
	}
};

data x[1<<19];
int n,m,l,r,h[MAXN];
long long d[MAXN];

void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]=data(h[l]+d[l-1],h[l]-d[l-1],1LL<<63);return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline data query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr);
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		d[i+n]=d[i];
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);h[i]<<=1;
		h[i+n]=h[i];
	}
	for (int i=1,p=n<<1;i<=p;i++) d[i]+=d[i-1];
	BuildTree(1,1,n<<1|1);
	while (m--)
	{
		scanf("%d %d",&l,&r);
		if (l<=r) printf("%lld\n",query(1,r+1,l+n,1,n<<1|1).ans);
		else printf("%lld\n",query(1,r+1,l,1,n<<1|1).ans);
	}
	return 0;
}