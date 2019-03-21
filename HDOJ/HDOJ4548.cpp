#include <cstdio>
#define MAXN 1000010
using namespace std;

int T,l,r,ans[MAXN],prime[MAXN],tot;
bool not_prime[MAXN];

int f(int x)
{
	int r=0;
	while (x){r+=x%10;x/=10;}
	return r;
}

void preWork()
{
	for (int i=2;i<=1000000;i++)
	{
		if (!not_prime[i]) prime[++tot]=i;
		for (int j=1;i*prime[j]<=1000000;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j])) break;
		}
	}
	for (int i=1;i<=tot;i++)
		if (!not_prime[f(prime[i])]) ans[prime[i]]=1;
	for (int i=1;i<=1000000;i++) ans[i]+=ans[i-1];
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	preWork();
	read(T);int c=1;
	while (T--)
	{
		read(l);read(r);printf("Case #%d: %d\n",c++,ans[r]-ans[l-1]);
	}
	return 0;
}
