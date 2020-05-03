#include <cstdio>
#define MOD 2011
#define MAXN 200010
using namespace std;

struct ansreturn
{
	long long amt;
	long long pos;
};

struct SegmentTree
{
	int p,r,m;
	int left,right;
	ansreturn a;
};

SegmentTree tree[MAXN*2];
long long v[MAXN],ans;
int n,m,top=1,root=1;
long long u,v1;
ansreturn res;

ansreturn mymax(ansreturn a,ansreturn b)
{
	return a.amt>b.amt?a:b;
}

void Build_A_Tree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].a.amt=v[tree[u].p];
		tree[u].a.pos=tree[u].p;
		return ;
	}
	tree[u].m=(tree[u].p+tree[u].r)>>1;
	top++;
	tree[u].left=top;
	tree[top].p=tree[u].p;tree[top].r=tree[u].m;
	Build_A_Tree(top);
	top++;
	tree[u].right=top;
	tree[top].p=tree[u].m;tree[top].r=tree[u].r;
	Build_A_Tree(top);
	tree[u].a=mymax(tree[tree[u].left].a,tree[tree[u].right].a);
	return ;
}

void modify(int u,int x)
{
	if (tree[u].p==x&&tree[u].p+1==tree[u].r)
	{
		tree[u].a.amt=0;
		return ;
	}
	if (x<tree[u].m) modify(tree[u].left,x);
	else modify(tree[u].right,x);
	tree[u].a=mymax(tree[tree[u].left].a,tree[tree[u].right].a);
	return ;
}

ansreturn query(int u,int ll,int rr)
{
	if (tree[u].p==ll&&tree[u].r==rr)
		return tree[u].a;
	if (rr<=tree[u].m) return query(tree[u].left,ll,rr);
	else if (ll>=tree[u].m) return query(tree[u].right,ll,rr);
	else return mymax(query(tree[u].left,ll,tree[u].m),query(tree[u].right,tree[u].m,rr));
}

int main()
{
	freopen("web.in","r",stdin);freopen("web.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	tree[1].p=1;tree[1].r=n+1;
	Build_A_Tree(root);
	while (m--)
	{
		scanf("%lld %lld",&u,&v1);
		res=query(root,u,v1+1);
		ans=(ans+(u+v1)*res.amt)%MOD;
		modify(root,res.pos);
	}
	printf("%lld\n",ans%MOD);
	return 0;
}