#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int n,prime[200],tot;

inline bool isprime(int x)
{
	if (x==2) return true;
	for (int i=2;i*i<=x;i++)
		if (!(x%i)) return false;
	return true;
}

int main()
{
	for (int i=3;i<=1009;i++) if (isprime(i)) prime[++tot]=i;
	scanf("%d",&n);
	int i=1;
	for (;prime[i]<n;i++);
	printf("%d\n%d %d\n",prime[i],1,n);
	i=prime[i]-n;
	for (int j=1;j<n;j++) printf("%d %d\n",j,j+1);
	for (int k=1,j=n/2+1;i--;j++,k++) printf("%d %d\n",j,k);
	return 0;
}