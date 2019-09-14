#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ls id<<1
#define rs id<<1|1
const int inf=0x3f3f3f3f;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100050;
int n,s,l;
int a[N];

struct segtree
{
	int l,r;
	int mn,mx;
}t[N<<2];
inline void pushup(int id)
{
	t[id].mx=max(t[ls].mx,t[rs].mx);
	t[id].mn=min(t[ls].mn,t[rs].mn);
}
void build(int l,int r,int id)
{
	t[id].l=l,t[id].r=r;
	if(l==r){
		t[id].mx=t[id].mn=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	pushup(id);
}
int querymin(int L,int R,int id)
{
	int l=t[id].l,r=t[id].r;
	if(L==l&&r==R)return t[id].mn;
	int mid=(l+r)>>1;
	if(R<=mid)return querymin(L,R,ls);
	else if(L>mid)return querymin(L,R,rs);
	else return min(querymin(L,mid,ls),querymin(mid+1,R,rs));
}
int querymax(int L,int R,int id)
{
	int l=t[id].l,r=t[id].r;
	if(L==l&&r==R)return t[id].mx;
	int mid=(l+r)>>1;
	if(R<=mid)return querymax(L,R,ls);
	else if(L>mid)return querymax(L,R,rs);
	else return max(querymax(L,mid,ls),querymax(mid+1,R,rs));
}
int now,L,ans;
int dp[N];
inline bool check(int l,int r)
{
	int mx=querymax(l,r,1);
	int mn=querymin(l,r,1);
	if(mx-mn<=s)return true;
	else return false;
}

int main()
{
	scanf("%d%d%d",&n,&s,&l);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	build(1,n,1);
	mem(dp,inf);dp[0]=0;
	int j=0;
	for(int i=1;i<=n;++i)
	{
		while((i-j>=l&&check(j+1,i)==false)||dp[j]==inf)j++;
		if(i-j>=l)dp[i]=min(dp[i],dp[j]+1);
	}
	if(dp[n]==inf)ans=-1;
	else ans=dp[n];
	printf("%d\n",ans);
	return 0;
}
