#include <cmath>
#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int A=29;
const int B=34483;
const int M=1000007;
const int t1m1=517245;
const int t2m2=482763;

int n,m,k,ans;
int invA[MAXN],invB[MAXN];
int facA[MAXN],facB[MAXN],invfacA[MAXN],invfacB[MAXN];

inline int LucasA(int n,int m)
{
	if (n<m) return 0;
	if (n<A&&m<A) return facA[n]*invfacA[m]*invfacA[n-m]%A;
	return LucasA(n/A,m/A)*LucasA(n%A,m%A)%A;
}

inline int LucasB(int n,int m)
{
	if (n<m) return 0;
	if (n<B&&m<B) return facB[n]*invfacB[m]%B*invfacB[n-m]%B;
	return LucasB(n/B,m/B)*LucasB(n%B,m%B)%B;
}

inline int C(int n,int m)
{
	int a=LucasA(n,m);
	int b=LucasB(n,m);
	int res=1LL*a*t1m1%M;
	return (res+1LL*b*t2m2%M)%M;
}

int main()
{
	invA[1]=facA[0]=invfacA[0]=1;
	for (int i=1;i<=A;i++) facA[i]=facA[i-1]*i%A;
	for (int i=2;i<A;i++) invA[i]=(A-A/i)*invA[A%i]%A;
	for (int i=1;i<=A;i++) invfacA[i]=invfacA[i-1]*invA[i]%A;
	invB[1]=facB[0]=invfacB[0]=1;
	for (int i=1;i<=B;i++) facB[i]=facB[i-1]*i%B;
	for (int i=2;i<B;i++) invB[i]=(B-B/i)*invB[B%i]%B;
	for (int i=1;i<=B;i++) invfacB[i]=invfacB[i-1]*invB[i]%B;
	scanf("%d %d %d",&n,&m,&k);
	for (int i=0;i<=k;i++)
	{
		if (1LL*(m+1)*i>k) break;
		int res=i&1?M-1:1;
		res=1LL*res*C(n,i)%M;
		res=1LL*res*C(n-1+k-(m+1)*i,k-(m+1)*i)%M;
		ans+=res;
		if (ans>=M) ans-=M;
	}
	printf("%d\n",ans);
	return 0;
}