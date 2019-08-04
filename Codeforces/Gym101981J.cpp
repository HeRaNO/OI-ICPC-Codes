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
int n;
int a[1000050];
ll ans;
vector <int> v[1000050];
int vis[1000050],pri[100050],tot;
inline void shaipri(){
	for(int i=2;i<=1000000;++i){
		if(!vis[i]){pri[++tot]=i;vis[i]=i;}
		for(int j=1;i*pri[j]<=1000000;++j){
			vis[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
}

inline void fenjie(int x,int pos){
	if(x==1)return;
	while(x>1){
		int t=vis[x];
		while(x%t==0)x/=t;
		v[t].push_back(pos);
	}
}

int main(){
	shaipri();
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=1000000;++i)v[i].push_back(0);
	for(int i=1;i<=n;++i){
		fenjie(a[i],i);
	}
	for(int i=1;i<=tot;++i){
		int siz=v[pri[i]].size();
		for(int j=1;j<siz;++j){
			ans=ans+((ll)n-(ll)v[pri[i]][j]+1LL)*((ll)v[pri[i]][j]-(ll)v[pri[i]][j-1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}