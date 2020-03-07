#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pb(x) push_back(x)
using namespace std;
const int N=100050;
ll n1,n2,n12;

int main()
{
	cin>>n1>>n2>>n12;
	ll ans=((n1+1)*(n2+1)-(n12+1))/(n12+1);;
	cout<<ans<<endl;
	return 0;
}
