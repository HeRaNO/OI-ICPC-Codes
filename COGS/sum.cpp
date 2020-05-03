#include <cstdio>
#define MAXN 10010
using namespace std;
 
struct rec
{
    int p,r,m;
    int left,right;
    long long sum;
};

rec tree[2*MAXN]={};
int n,m;
int top=1;
long long x[MAXN];
 
void Build_A_Tree(int u)
{
    if (tree[u].p+1==tree[u].r)
    {
        tree[u].sum=x[tree[u].p];
        return ;
    }
    tree[u].m=(tree[u].p+tree[u].r)/2;
    top++;
    tree[u].left=top;
    tree[top].p=tree[u].p;
    tree[top].r=tree[u].m;
    Build_A_Tree(top);
    top++;
    tree[u].right=top;
    tree[top].p=tree[u].m;
    tree[top].r=tree[u].r;
    Build_A_Tree(top);
    tree[u].sum=tree[tree[u].left].sum+tree[tree[u].right].sum;
}

long long query (int u,int a,int b)
{
    if ((tree[u].p==a)&&(tree[u].r==b))
        return tree[u].sum;
    if (tree[u].m>=b) return query(tree[u].left,a,b);
    else if (tree[u].m<=a) return query(tree[u].right,a,b);
    else return query(tree[u].left,a,tree[u].m)+query(tree[u].right,tree[u].m,b);
}

int main()
{
    freopen("sum.in","r",stdin);freopen("sum.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    tree[1].p=1;
    tree[1].r=n+1;
    Build_A_Tree(1);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%lld\n",query(1,a,b+1));
    }
    return 0;
}