#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pb(x) push_back(x)
using namespace std;
const int N=300050;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int c[N],n;

void solve()
{
	cin>>n;
	double ans=1.0;
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	for(int i=1;i<=n;++i)
	{
		if(c[i]*1.0/i>1.0){printf("-1\n");return;}
		ans=min(ans,1.0*c[i]/i);
	}
	printf("%.10lf\n",ans);
}

int main()
{
	int Test=1;
//    cin>>Test;
	while(Test--)
	{
		solve();
	}
	return 0;
}
