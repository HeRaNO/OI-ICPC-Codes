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
char s[1050];

int main(){
	int T;cin>>T;
	while(T--){
		scanf("%s",s);n=strlen(s);
		int las=s[0]-'a';
		bool flag=true;
		for(int i=1;i<n;++i){
			int num=s[i]-'a';
			if(!(num==las+1||(las==25&&num==0))){
				flag=0;
				break;
			}
			las=num;
		}
		if(!flag)puts("NO");
		else puts("YES");
	}
	return 0;
}
