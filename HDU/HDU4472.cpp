#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=100050;
const ll mod=1e9+7;
ll a[N];

ll work(ll x)
{
	ll ret=0;
	for(int i=1;i<x;++i)
		if((x-1)%i==0)ret+=a[i],ret%=mod;
	return ret;
}

void Init()
{
	a[1]=a[2]=1;
	for(int i=3;i<=1000;++i)
		a[i]=work(i);
}

int main()
{
	Init();
	int n,kase=1;
	while(scanf("%d",&n)==1)
	{
		cout<<"Case "<<kase<<": "<<a[n]<<endl;
		kase++;
	}
	return 0;
}