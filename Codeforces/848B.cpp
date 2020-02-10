#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=300050;
const int DELTA=100000;
const int inf=0x3f3f3f3f;
int h,w,n;
vector <int> X[N],Y[N];
struct point
{
	int x,y,ex,ey,id,s;
}a[N],b[N],ans[N];
bool cmp1(const point &X,const point &Y)
{
	if(X.s<Y.s)return true;
	else if(X.s>Y.s)return false;
	else
	{
		if(X.x<Y.x)return true;
		else return false;
	}
}
bool cmp2(const point &X,const point &Y)
{
	if(X.s<Y.s)return true;
	else if(X.s>Y.s)return false;
	else
	{
		if(X.ex<Y.ex)return true;
		else if(X.ex==Y.ex)return X.ey>Y.ey;
		else return false;
	}
}

int main()
{
	cin>>n>>w>>h;
	for(int i=1;i<=n;++i)
	{
		int g,p,t;
		scanf("%d%d%d",&g,&p,&t);
		a[i].id=i;
		if(g==1)
		{
			a[i].x=p;
			a[i].y=-t;
			a[i].ex=p;a[i].ey=h;
		}
		else
		{
			a[i].y=p;
			a[i].x=-t;
			a[i].ey=p;a[i].ex=w;
		}
		a[i].s=a[i].x+a[i].y;
		b[i]=a[i];
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	for(int i=1;i<=n;++i)
	{
		ans[a[i].id].x=b[i].ex;
		ans[a[i].id].y=b[i].ey;
	}
	for(int i=1;i<=n;++i)
		printf("%d %d\n",ans[i].x,ans[i].y);
	return 0;
}