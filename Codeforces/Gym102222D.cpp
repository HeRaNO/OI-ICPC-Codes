#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e6+10,INF=0x7fffffff;
const ll llINF=0x7fffffffffffffff,MOD=1e9+7;
#define lowbit(x) x&-x

int n,m;

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&m);
		double ans1,ans2;
		if(n==1)ans1=1;
		else ans1=(double)0.5;
		ans2=(m+1.0)/(2.0*m);
		printf("Case #%d: %.6f %.6f\n",i,ans1,ans2);
	}
	return 0;
}
