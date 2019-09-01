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
const int N=105;
int n;
struct point{
	double x,y;
	point operator - (const point &P)const{
		return (point){x-P.x,y-P.y};
	}
	double normal()const{
		return hypot(x,y);
	}
}p[N],pe;
double ans;
inline double dot(point A,point B){
	return A.x*B.x+A.y*B.y;
}

int main(){
	int Test;cin>>Test;
	for(int TEST=1;TEST<=Test;++TEST){
		read(n);ans=0;
		for(int i=0;i<n;++i){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		p[n]=p[0];p[n+1]=p[1];
		scanf("%lf%lf",&pe.x,&pe.y);
		for(int i=0;i<n;++i){
			double r=(pe-p[i+1]).normal();
			point A=p[i+1]-p[i],B=p[i+2]-p[i+1];
			ans+=r*acos(dot(A,B)/(A.normal()*B.normal()));
		}
		printf("Case #%d: %.3lf\n",TEST,ans);
	}
	return 0;
}