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
string a[20];
int dp[20][70000];
int len[20][70000];
int tot,ans,all;
int cnt[20];
string s[20][70000];
string p;
int n;
void printall(int id,int step,string res){
	if(step==a[id].length()){
		s[id][++tot]=res;
		return;
	}
	printall(id,step+1,res);
	printall(id,step+1,res+a[id][step]);
}

int main(){
	cin>>n;all=(1<<n);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		p.clear();tot=0;
		printall(i,0,p);
		sort(s[i]+1,s[i]+tot+1);
		cnt[i]=tot;
	}
	mem(dp,-0x3f);ans=dp[0][0];
	for(int i=2;i<=cnt[1];++i)
		dp[1][i]=max(dp[1][i-1],(int)s[1][i].length());
	
	for(int i=2;i<=n;++i){
		int k=1;
		for(int j=2;j<=cnt[i];++j){
			while(k<=cnt[i-1]&&s[i][j]>s[i-1][k])k++;
			dp[i][j]=max(dp[i][j-1],dp[i-1][k-1]+(int)s[i][j].length());
		}
	}
	ans=max(ans,dp[n][cnt[n]]);
	if(ans<0)ans=-1;
	cout<<ans<<endl;
	return 0;
}
