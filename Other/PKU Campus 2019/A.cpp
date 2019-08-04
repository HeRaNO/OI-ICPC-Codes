#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
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
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define defor(i,a,b) for(int i=a;i>=b;--i)
#define infor(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=10000019LL;
const double pi=acos(-1.0);
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
int n,m;
int f[200050];
int e[200050];
int node[200050];
bool huan[200050];
bool vis[200050];
bool zihuan[200050];
bool youjie;
ll ans;
int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}
inline void data_init(){
	for(int i=1;i<=m;++i)f[i]=i;
	youjie=true;
	ans=1;
	mem(e,0);
	mem(huan,0);
	mem(vis,0);
	mem(node,0);
	mem(zihuan,0);
}


int main(){
	int T;cin>>T;
	while(T--){
		read(n),read(m);
		data_init();
		for(int i=1;i<=n;++i){
			int x,y;read(x),read(y);
			int fx=Find(x),fy=Find(y);
			if(x==y){zihuan[fx]=1,e[fx]++;continue;}
			if(fx!=fy){
				f[fy]=fx;
				e[fx]+=e[fy]+1;
				zihuan[fx]|=zihuan[fy];
			}
			else{
				e[fx]++;
			}
		}
		for(int i=1;i<=m;++i){
			int ff=Find(i);
			node[ff]++;
		}
		for(int i=1;i<=m;++i){
			int ff=Find(i);
			if(vis[ff])continue;
			vis[ff]=1;
			if(e[ff]>node[ff]){youjie=0;break;}
			if(e[ff]==node[ff]){
				if(zihuan[ff]==true)continue;
				ans*=2;ans%=mod;
			}
			if(e[ff]<node[ff]){
				ans*=(ll)node[ff];
				ans%=mod;
			}
		}
		if(youjie==false){puts("0");continue;}
		printf("%lld\n",ans);
	}
	return 0;
}