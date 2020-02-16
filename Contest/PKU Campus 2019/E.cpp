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
const ll mod=1e9+7;
const double pi=acos(-1.0);
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
const int N=100050;
int pri[N],vis[N],tot,las,ans;
int n,m;
vector <int> v1[N],v2;
inline void data_init(){
	for(int i=1;i<=100000;++i)v1[i].clear();
	v2.clear();las=0;
}
inline void shaipri(){
	for(int i=2;i<=100000;++i){
		if(!vis[i]){pri[++tot]=i;vis[i]=i;}
		for(int j=1;i*pri[j]<=100000;++j){
			vis[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
}

int main(){
	shaipri();
	int T;cin>>T;
	while(T--){
		data_init();
		read(n),read(m);
		for(int i=1;i<=n;++i){
			int x;read(x);
			for(int j=1;j*j<=x;++j){
				if(x%j==0){
					v1[j].push_back(i);
					int t=x/j;
					if(t*t!=x)v1[t].push_back(i);
				}
			}
		}
		for(int i=1;i<=m;++i){
			int l,r,x;read(l),read(r),read(x);
			l^=las,r^=las,x^=las;
			ans=0;
			v2.clear();
			while(x>1){
				int t=vis[x];
				while(x%t==0)x/=t;
				int siz=v2.size();
				for(int j=0;j<siz;++j)
					v2.push_back(t*v2[j]);
				v2.push_back(t);
			}
			int siz=v2.size();
			int f=1;
			for(int j=0;j<siz;++j){
				if(j%2==0)f=1;
				else f=-1;
				int tmp=upper_bound(v1[v2[j]].begin(),v1[v2[j]].end(),r)-lower_bound(v1[v2[j]].begin(),v1[v2[j]].end(),l);
				ans+=tmp*f;
			}
			ans=(r-l+1)-ans;
			printf("%d\n",las=ans);
		}
	}
	return 0;
}