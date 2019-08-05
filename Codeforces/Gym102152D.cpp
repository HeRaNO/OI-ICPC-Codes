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
#include <bitset>
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
struct chuan{
	int cnt;
	char s[15];
	inline void init_(){
		mem(s,0);
		cnt=0;
	}
}a[3];
inline bool cmp(const chuan &x,const chuan &y){
	return x.cnt>y.cnt;
}

int main(){
	int T;cin>>T;
	while(T--){
		for(int i=1;i<=3;++i)a[i].init_();
		for(int i=1;i<=3;++i){
			scanf("%s",a[i].s);
			for(int j=0;j<10;++j){
				if(a[i].s[j]=='1')a[i].cnt++;
			}
		}
		if(a[1].cnt+a[2].cnt+a[3].cnt<=10){
			for(int i=1;i<=a[1].cnt+a[2].cnt+a[3].cnt;i++)printf("1");
			for(int i=a[1].cnt+a[2].cnt+a[3].cnt+1;i<=10;i++)printf("0");
			puts("");
			continue;
		}
		sort(a+1,a+4,cmp);
		int A=a[1].cnt,B=a[2].cnt;
		int R=10-(A-B),L=max(10-(A+B),A+B-10);
		if(a[3].cnt<=L){
			for(int i=1;i<=10-L+a[3].cnt;++i)printf("1");
			for(int j=11-L+a[3].cnt;j<=10;++j)printf("0");
			puts("");
			continue;
		}
		if(a[3].cnt>=R){
			for(int i=1;i<=10;++i)printf("1");
			puts("");
			continue;
		}
		int t,mn=100;
		for(int i=L;i<=R;i+=2){
			if(abs(a[3].cnt-i)<mn){
				mn=abs(a[3].cnt-i);
				t=i;
			}
		}
		for(int i=1;i<=10-mn;++i)printf("1");
		for(int i=11-mn;i<=10;++i)printf("0");
		puts("");
		continue;
	}
	return 0;
}