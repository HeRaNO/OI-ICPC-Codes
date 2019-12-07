#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct Matrix
{
	int m[5][5];
	Matrix(){
		memset(m,0x3f,sizeof m);
		return ;
	}
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		for (int i=0;i<5;i++)
			for (int j=0;j<5;j++)
				for (int k=0;k<5;k++)
					res.m[i][j]=min(res.m[i][j],m[i][k]+a.m[k][j]);
		return res;
	}
};

struct SegmentTree
{
	int p,r,m;Matrix x;
};

SegmentTree tree[1<<19];
int n,T,l,r;
char a[MAXN];

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		for (int i=0;i<5;i++) tree[u].x.m[i][i]=0;
		switch(a[tree[u].p])
		{
			case '2':tree[u].x.m[0][0]=1,tree[u].x.m[0][1]=0;break;
			case '0':tree[u].x.m[1][1]=1,tree[u].x.m[1][2]=0;break;
			case '1':tree[u].x.m[2][2]=1,tree[u].x.m[2][3]=0;break;
			case '6':tree[u].x.m[3][3]=1,tree[u].x.m[4][4]=1;break;
			case '7':tree[u].x.m[4][4]=0,tree[u].x.m[3][4]=0;break;
		}
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x*tree[u<<1|1].x;
	return ;
}

inline Matrix query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)*query(u<<1|1,tree[u].m,r);
}

int main()
{
	scanf("%d %d",&n,&T);scanf("%s",a+1);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (T--)
	{
		scanf("%d %d",&l,&r);
		Matrix p=query(1,l,r+1);
		printf("%d\n",p.m[0][4]==0x3f3f3f3f?-1:p.m[0][4]);
	}
	return 0;
}