#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=2e5+10;
const int MOD=1e9+7;
const ll llINF=((1ll<<61));

double ans;
double a[MAXN][2];
double loc[5][5];

struct Node
{
	double dis;
	int id;
}q[MAXN],p[MAXN];

bool cmp(Node a,Node b)
{
	return a.dis<b.dis;
}

int main()
{
	for(int i=1;i<=3;i++)
		scanf("%lf%lf",&loc[i][1],&loc[i][2]);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		double tx,ty;
		scanf("%lf%lf",&tx,&ty);
		double now=sqrt((tx-loc[3][1])*(tx-loc[3][1])+(ty-loc[3][2])*(ty-loc[3][2]));
		ans+=now*2;
		q[i].id=p[i].id=i;
		q[i].dis=sqrt((tx-loc[1][1])*(tx-loc[1][1])+(ty-loc[1][2])*(ty-loc[1][2]))-now;
		p[i].dis=sqrt((tx-loc[2][1])*(tx-loc[2][1])+(ty-loc[2][2])*(ty-loc[2][2]))-now;
	}
	sort(q+1,q+n+1,cmp);
	sort(p+1,p+n+1,cmp);
	if(q[1].id!=p[1].id)
		printf("%.12lf",ans+min(q[1].dis+p[1].dis,min(q[1].dis,p[1].dis)));
	else
		printf("%.12lf",ans+min(q[1].dis+p[2].dis,min(q[2].dis+p[1].dis,min(q[1].dis,p[1].dis))));
	return 0;
}