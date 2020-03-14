#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pb(x) push_back(x)
using namespace std;
const int N=300050;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
double n,v;
int a[N];

int main()
{
	cin>>n>>v;
	n=n*v;
	for(int i=1;i<=9;++i)
	{
		cout<<fixed<<setprecision(0)<<ceil(n*(i/10.0))<<" ";
	}
	return 0;
}
