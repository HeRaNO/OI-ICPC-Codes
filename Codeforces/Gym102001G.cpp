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
const ll mod=(1LL<<32);
const double pi=acos(-1.0);
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
int n,m;
int a[505][505];
int b[505][505];
int du[505];
int tmp[505];
int ans=-1;
inline void co1(){
	for(int i=1;i<=n;++i){
		tmp[i]=du[i];
	}
}
inline void co2(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			b[i][j]=a[i][j];
		}
	}
}

inline bool check(int x){
	co1();co2();
	bool flag=false;
	int cnt=m;
	while(true){
		flag=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(i==j)continue;
				if(b[i][j])continue;
				if(tmp[i]+tmp[j]>=x){
					tmp[i]++;tmp[j]++;
					b[i][j]=b[j][i]=1;
					cnt++;
					flag=1;
				}
			}
		}
//		cout<<cnt<<endl;
		if(cnt*2==n*n-n)return true;
		if(!flag)return false;
	}
	return true;
}

int main(){
	read(n),read(m);
	for(int i=1;i<=m;++i){
		int x,y;read(x),read(y);
		a[x][y]=a[y][x]=1;
		du[x]++;du[y]++;
	}
	int L=0,R=1000;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid))ans=mid,L=mid+1;
		else R=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
