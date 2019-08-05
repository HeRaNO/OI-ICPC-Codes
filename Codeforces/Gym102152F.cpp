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
char s[105];
int cnt;

int main(){
	int T;cin>>T;
	while(T--){
		cnt=0;
		scanf("%s",s);
		int n=strlen(s);
		for(int i=0;i<n;++i){
			if(s[i]>='A'&&s[i]<='Z')cnt++;
		}
		if(cnt<=6)puts("YES");
		else puts("NO");
	}
	return 0;
}