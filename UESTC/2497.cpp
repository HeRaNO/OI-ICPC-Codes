#include <bits/stdc++.h>
#define MAXN 10000005
using namespace std;

const int M=1e9+7;

// low[i]: min{p^e}
// S[i]=\sum_{pq=i} mu(p)phi(q)

int T,n;
int prime[MAXN],low[MAXN],S[MAXN],tot;
bool not_prime[MAXN];

inline void fadd(int &x,int y){x+=y;if (x>=M) x-=M;return ;}
inline int sqr(int x){return 1LL*x*x%M;}
inline int f(int x){return 1LL*x*(x+1)/2%M;}

inline void LinearShaker(int n)
{
	S[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i])
		{
			prime[++tot]=i;
			S[i]=i-2;low[i]=i;
		}
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j]))
			{
				low[i*prime[j]]=low[i]*prime[j];
				if (low[i]==i)
				{
					if (i==prime[j]) S[i*prime[j]]=S[i]*prime[j]+1;
					else S[i*prime[j]]=S[i]*prime[j];
				}
				else S[i*prime[j]]=S[i/low[i]]*S[low[i]*prime[j]];
				break;
			}
			S[i*prime[j]]=S[i]*S[prime[j]];
			low[i*prime[j]]=prime[j];
		}
	}
	for (int i=1;i<=n;i++) S[i]=1LL*S[i]*sqr(i)%M;
	for (int i=1;i<=n;i++) fadd(S[i],S[i-1]);
	return ;
}

int main()
{
	LinearShaker(10000000);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);int ans=0;
		for (int l=1,r;l<=n;l=r+1)
		{
			r=n/(n/l);
			int t=S[r];fadd(t,M-S[l-1]);
			t=1LL*t*sqr(f(n/l))%M;fadd(ans,t);
		}
		printf("%d\n",ans);
	}
	return 0;
}