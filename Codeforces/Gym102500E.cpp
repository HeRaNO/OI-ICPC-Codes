#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define flush fflush(stdout)
#define pb(x) push_back(x)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=1000050;
int t[10];
int c;

void solve()
{
	sort(t+1,t+5);
	if(t[2]+t[3]+t[4]<=3*c)
	{
		puts("infinite");
		return;
	}
	int x=3*c-t[2]-t[3];
	if(x>=t[1]&&x<=t[4])
	{
		printf("%.2lf\n",x/100.0);
		return;
	}
	puts("impossible");
}

int main()
{
	for(int i=1;i<=4;++i)
	{
		int x,y;
		scanf("%d.%d",&x,&y);
		t[i]=x*100+y;
	}
	int x,y;
	scanf("%d.%d",&x,&y);
	c=x*100+y;
	solve();
	return 0;
}
