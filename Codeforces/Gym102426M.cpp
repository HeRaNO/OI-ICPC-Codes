#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=5e5+10;
const int MOD=1e9+7;
const ll llINF=~(1ll<<63);

const double Pi=acos(-1);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double n,r,l;
		scanf("%lf%lf%lf",&n,&r,&l);
		if(l>=r*2)
		{
			printf("%.6lf\n",Pi*r*r*n);
			continue;
		}
		double ang=2*asin(l/r/2);
		double h=sqrt(r*r-l*l/4);
		double ans=n*ang*r*r;
		if(n)
			ans+=2*asin(h/r)*r*r-h*l;
		ans+=h*n*l;
		printf("%.6lf\n",ans);
	}
	return 0;
}