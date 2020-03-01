#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=300050;
int n,ans=inf;

int main()
{
	cin>>n;
	for(int i=1;i<=sqrt(n);++i)
	{
		if(n%i)continue;
		ans=min(ans,2*(n/i+i));
	}
	cout<<ans<<endl;
	return 0;
}
