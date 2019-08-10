#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <complex>
#include <bitset>
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define defor(i,a,b) for(int i=a;i>=b;--i)
#define infor(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=1e9+7;
const double pi=acos(-1.0);
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
ll n,m;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

int main(){
	while(scanf("%lld%lld",&n,&m)==2){
		if(n==0&&m==0)break;
		ll b=m*m;
		ll a=n*(m-1);
		if(b==0){
			printf("1/0\n");
			continue;
		}
		ll g=gcd(a,b);
		b/=g,a/=g;
		printf("%lld/%lld\n",a,b);
	}
	return 0;
}