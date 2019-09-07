#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
const int INF=0x7fffffff;
const int MOD=20100403;
int a[MAXN],b[MAXN],num[MAXN],ans[MAXN],n,m,cnt;

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int val)
{
	if(x==0)return;
	while(x<=n)
	{
		num[x]+=val;
		x+=lowbit(x);
	}
}

int query(int x)
{
	int ans=0;
	while(x)
	{
		ans+=num[x];
		x-=lowbit(x);
	}
	return ans;
}

struct QUERY
{
	int l,r,id;
}q[MAXN];

bool cmp(QUERY a,QUERY b)
{
	return a.r<b.r;
}

struct Node
{
	int l,r;
}p[MAXN*20];

bool cmp2(Node a,Node b)
{
	return a.r<b.r;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]=i;
	for(int i=1;i<=m;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=i*2;j<=n;j+=i)
			p[++cnt]={min(b[i],b[j]),max(b[j],b[i])};
	sort(p+1,p+cnt+1,cmp2);
	int nowr,cur2=0;
	for(int cur=1;cur<=m;cur++)
	{
		nowr=q[cur].r;
		while(p[cur2+1].r<=nowr&&cur2<=cnt)
			add(p[++cur2].l,1);
		ans[q[cur].id]=query(q[cur].r)-query(q[cur].l-1);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}
