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
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
int ans,n;
int tmp;
char s[250005];

int main(){
	cin>>n;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='V'&&tmp>0){ans=max(ans,tmp);tmp=0;continue;}
		if(s[i]=='V'){tmp=1;ans=max(ans,tmp);tmp=0;continue;}
		if(s[i]==s[i-1]){ans=max(ans,tmp);tmp=1;continue;}
		tmp++;ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}
