#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,inv[MAXN];

inline bool isprime(int x)
{
	if (x==2) return true;
	for (int i=2;i*i<=x;i++) if (!(x%i)) return false;
	return true;
}

int main()
{
	scanf("%d",&n);inv[1]=1;
	if (n==4) return printf("YES\n1\n3\n2\n4\n"),0;
	if (!isprime(n)) return puts("NO"),0;
	for (int i=2;i<n;i++) inv[i]=1LL*(n-n/i)*inv[n%i]%n;
	puts("YES\n1");
	for (int i=2;i<n;i++) printf("%d\n",1LL*inv[i-1]*i%n);
	if (n!=1) printf("%d\n",n);
	return 0;
}