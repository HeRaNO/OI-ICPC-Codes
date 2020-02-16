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
#define con continue
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
inline void file_init(){
	freopen("right-turn-only.in","r",stdin);
	freopen("right-turn-only.out","w",stdout);
}
ll x,y;

int main(){
	file_init();
	int T;cin>>T;
	while(T--){
		read(x),read(y);
		if(x==0&&y==0){puts("0");continue;}
		if(x==0&&y>0){printf("%lld\n",y);continue;}
		if(x==0&&y<0){printf("%lld\n",4+abs(y));continue;}
		if(x>0&&y==0){printf("%lld\n",2+x);con;}
		if(x<0&&y==0){printf("%lld\n",4+abs(x));con;}
		if(x>0&&y>0){printf("%lld\n",x+y);con;}
		if(x>0&&y<0){printf("%lld\n",2+x+abs(y));con;}
		if(x<0&&y>0){printf("%lld\n",4+abs(x)+y);con;}
		if(x<0&&y<0){printf("%lld\n",4+abs(x)+abs(y));con;}
	}
	return 0;
}
