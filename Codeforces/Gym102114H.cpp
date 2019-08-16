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
int n;
int dp[N][25];
int ans,ansl,ansr,cnt;
int tl,tr;
int ml,mr;
char s[N];int a[N],b[25];
int L[N][25],R[N][25];
inline void data_init(){
//	mem(L,0);mem(R,0);
	ans=ansl=ansr=0;
	ml=10,mr=0;tl=tr=0;
}

inline int work(int x){
	mem(dp[0],0);
	for(int i=1;i<=n;++i){
		for(int j=0;j<x;++j){
			dp[i][j]=dp[i-1][j];
			L[i][j]=L[i-1][j];
			R[i][j]=R[i-1][j];
			if(a[i]==b[j]){
				dp[i][j]++;
				if(tl==j&&L[i][j]==0)L[i][j]=i;
				if(tr==j)R[i][j]=i;
			}
			if(dp[i][j]<dp[i][j-1]){
				dp[i][j]=dp[i][j-1];
				L[i][j]=L[i][j-1];
				R[i][j]=R[i][j-1];
			}
		}
	}
	return dp[n][x-1];
}

int main(){
	int T;read(T);
	while(T--){
		data_init();
		read(n);
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)a[i]=s[i]-'0';
		for(int i=1;i<=n;++i){
			ml=min(ml,a[i]);
			mr=max(mr,a[i]);
		}
		for(int i=0;i<10;++i)b[i]=i;
		ans=work(10);ansl=ansr=1;
		for(int l=ml;l<=mr;++l){
			for(int r=ml;r<l;++r){
				cnt=0;
				for(int k=0;k<=r;++k)b[cnt++]=k;tl=cnt;
				for(int k=l;k>=r;--k)b[cnt++]=k;tr=cnt-1;
				for(int k=l;k<10;++k)b[cnt++]=k;
				int tmp=work(cnt);
				if(tmp>ans&&L[n][cnt-1]&&R[n][cnt-1]){
					ans=tmp;
					ansl=L[n][cnt-1];ansr=R[n][cnt-1];
				}
			}
		}
		printf("%d %d %d\n",ans,ansl,ansr);
	}
	return 0;
}
/*
1
6
123546
*/