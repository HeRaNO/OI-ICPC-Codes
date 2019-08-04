#include <bits/stdc++.h>
#define MAXN 16
using namespace std;

int T,n,x,y,z,l,r,p,M,inv2,a[1<<MAXN|1],b[1<<MAXN|1];

inline int fpow(int a,int b)
{
	int r=1;
	for (;b;b>>=1,a=(a*a)%M) if (b&1) r=(r*a)%M;
	return r%M;
}

inline void FWT_Xor(int c[], int n, bool f)
{
	int x, y;
	for (int i = 1; i < n; i <<= 1)
		for (int p = i << 1, j = 0; j < n; j += p)
			for (int k = 0; k < i; k++)
			{
				x = c[j + k];
				y = c[j + k + i];
				c[j + k] = (x + y) % M;
				c[j + k + i] = (x - y + M) % M;
				if (f)
				{
					(c[j + k] *= inv2) %= M;
					(c[j + k + i] *= inv2) %= M;
				}
			}
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(a,0,sizeof a);memset(b,0,sizeof b);
		scanf("%d %d %d %d %d",&n,&x,&y,&z,&M);
		inv2=fpow(2,M-2);
		for (int i=1;i<=x;i++)
		{
			scanf("%d %d %d",&l,&r,&p);p=(p+M)%M;
			a[l]=(a[l]+p)%M;a[r+1]=(a[r+1]-p+M)%M;
		}
		for (int i=1;i<=y;i++)
		{
			scanf("%d %d %d",&l,&r,&p);p=(p+M)%M;
			b[l]=(b[l]+p)%M;b[r+1]=(b[r+1]-p+M)%M;
		}
		for (int i=0;i<(1<<n);i++) (a[i]+=a[i-1])%=M,(b[i]+=b[i-1])%=M;
		FWT_Xor(a,1<<n,false);FWT_Xor(b,1<<n,false);
		for (int i=0;i<(1<<n);i++) (a[i]*=b[i])%=M;
		FWT_Xor(a,1<<n,true);
		for (int i=1;i<(1<<n);i++) (a[i]+=a[i-1])%=M;
		for (int i=1;i<=z;i++)
		{
			scanf("%d %d",&l,&r);
			if (!l) printf("%d%c",a[r],i==z?'\n':' ');
			else printf("%d%c",(a[r]-a[l-1]+M)%M,i==z?'\n':' ');
		}
	}
	return 0;
}