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
typedef pair<int,int> pii;
const ll mod=(1LL<<32);
const double pi=acos(-1.0);
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
int n,s;
ll A[40],B[20];
int ta,tb;
int cnta,cntb;
int order[50];
int seA[50];
bool seB[50];
ll v[2],ans=-mod;
inline bool cmp(const int &x,const int &y){
	return x>y;
}
pii dfs(int a,int b,pii v,int step){
	if(step==2*n*(s+1)+1){
		return v;
	}//cout<<a<<" "<<b<<" "<<v.first<<" "<<v.second<<endl;
	pii temp=v;
	int id=order[step];int team=(id>n)?1:0;
	if(team==0){
		if(seA[id]<s){
			seA[id]++;
            pii tt=dfs(a-1,b,make_pair(v.first+A[a],v.second),step+1);
            temp=tt;
			seA[id]--;
		}
		if(seB[id]==false){
			seB[id]=true;
			pii tt=dfs(a,b-1,make_pair(v.first+B[b],v.second),step+1);
			if(tt.first>temp.first)
                temp=tt;
			seB[id]=false;
		}
	}
	if(team==1){
		if(seA[id]<s){
			seA[id]++;
			pii tt=dfs(a-1,b,make_pair(v.first,v.second+A[a]),step+1);
			temp=tt;
			seA[id]--;
		}
		if(seB[id]==false){
			seB[id]=true;
			pii tt=dfs(a,b-1,make_pair(v.first,v.second+B[b]),step+1);
			if(tt.second>temp.second)
                temp=tt;
			seB[id]=false;
		}
	}
	return temp;
}

int main(){
	read(n),read(s);
	for(int i=1;i<=2*n*(s+1);++i)read(order[i]);
	read(cnta);ta=cnta;
	for(int i=1;i<=cnta;++i)read(A[i]);
	sort(A+1,A+cnta+1);
	read(cntb);tb=cntb;
	for(int i=1;i<=cntb;++i)read(B[i]);
	sort(B+1,B+cntb+1);
	pii ans=dfs(ta,tb,make_pair(0,0),1);
	printf("%d\n",ans.first-ans.second);
	return 0;
}
