#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,x,nxt[MAXN],p[MAXN],l[MAXN<<2],cir[MAXN];
long long a[MAXN],m[MAXN];
char s[MAXN],t[MAXN],f[MAXN],g[MAXN];
bool vis[MAXN];

long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if (!b){x=1;y=0;return a;}
	long long res=exgcd(b,a%b,x,y);
	long long t=x;x=y;y=t-(a/b)*y;
	return res;
}

inline long long exCRT(int n)
{
	if (!n) return -1;
	long long M=m[1],ans=a[1],x,y;
	for (int i=2;i<=n;i++)
	{
		long long g=exgcd(M,m[i],x,y);
		if ((a[i]-ans)%g) return -1LL;
		x=(a[i]-ans)/g*x%(m[i]/g);
		ans+=x*M;M=M/g*m[i];ans%=M;
	}
	return (ans+M)%M;
}

inline void GetNext(char S[],int n)
{
	int i=0,j=-1;nxt[0]=-1;
	while (i!=n)
	{
		if (!~j||S[i]==S[j]) nxt[++i]=++j;
		else j=nxt[j];
	}
	return ;
}

inline void KMP(char S[],char T[],int n)
{
	int i=0,j=0;
	while (i<(n<<2)&&j<n)
	{
		if (!~j||S[i%n]==T[j])
		{
			++i;++j;
			if (j==n)
			{
				l[++l[0]]=i-n;j=nxt[j-1];
				--i;
			}
		}
		else j=nxt[j];
	}
	return ;
}

inline bool calc(int n)
{
	for (int i=1;i<=n;i++) f[i-1]=s[cir[i]],g[i-1]=t[cir[i]];
	l[0]=0;GetNext(g,n);KMP(f,g,n);
	if (!l[0]) return false;
	m[++x]=l[2]-l[1];a[x]=l[1];
	return true;
}

int main()
{
	scanf("%s",s);scanf("%s",t);n=strlen(s);
	for (int i=0;i<(n>>1);i++) p[i]=i<<1;
	for (int i=n>>1;i<n;i++) p[i]=(i-(n>>1))<<1|1;
	for (int i=0;i<n;i++)
		if (!vis[i])
		{
			cir[0]=0;
			for (int j=i;!vis[j];j=p[j]) vis[j]=true,cir[++cir[0]]=j;
			if (!calc(cir[0])) return puts("-1"),0;
		}
	printf("%lld\n",exCRT(x));
	return 0;
}