#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define infor(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a,b) memset(a,b,sizeof(a))
const int N=500050;

int n,m;
int a[N];
struct segtree
{
	int l,r;
	int mx;
}t[N<<2];

void build(int l,int r,int id)
{
	t[id].l=l,t[id].r=r;
	if(l==r)
	{
		t[id].mx=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	t[id].mx=max(t[ls].mx,t[rs].mx);
}

int query(int l,int r,int val,int id)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(t[rs].mx>=val)return query(mid+1,r,val,rs);
	else return query(l,mid,val,ls);
}


int main(){
	scanf("%d%d",&n,&m);
	infor(i,1,n)
	{
		scanf("%d",&a[i]);
	}
	build(1,n,1);
	for(int i=1;i<n;++i)
	{
		int ans=query(1,n,a[i]+m,1);
		if(ans<=i)ans=-1;
		printf("%d ",ans==-1?ans:ans-i-1);
	}
	printf("-1");
	return 0;
}