#include <bits/extc++.h>
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
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
const int N=205;
int dp[N][N][N];
int n,Q;
struct node{
	int id;
	int val;
}a[N];
inline bool cmp(const node &x,const node &y){
	return x.val<y.val;
}

inline void floyd(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dp[k][i][j]=min(dp[k-1][i][j],dp[k-1][i][a[k].id]+dp[k-1][a[k].id][j]);
			}
		}
	}
}

int main(){
	int Test;cin>>Test;
	for(int TEST=1;TEST<=Test;TEST++){
		mem(dp,inf);
		read(n),read(Q);
		for(int i=1;i<=n;++i){
			a[i].id=i;
			read(a[i].val);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				read(dp[0][i][j]);
			}
		}
		sort(a+1,a+n+1,cmp);
		floyd();
		printf("Case #%d:\n",TEST);
		while(Q--){
			int u,v,w;
			read(u),read(v),read(w);
			int now=0;
			for(int i=1;i<=n;++i){
				if(a[i].val<=w)now=i;
			}
			printf("%d\n",dp[now][u][v]);
		}
	}
	return 0;
}