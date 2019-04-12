#include <cstdio>
#define MAXN 2005
using namespace std;

int n,T,cnt,a[MAXN],ans,s;

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);printf("Case #%d:",++cnt);s=0;
		for (int i=1;i<=n;i++)
		{
			read(a[i]);s+=a[i];a[i+n]=a[i];
		}
		a[0]=a[n];a[n<<1|1]=a[1];
		for (int i=1;i<=n;i++)
		{
			ans=s-max(a[i-1],a[i]);
			long long t=0;
			for (int j=0;j<n-2;j++)
			{
				t+=a[i+j];ans=min(ans,t+s-a[i+j+1]);
			}
			t=0;
			for (int j=1;j<n-1;j++)
			{
				t+=a[(i-j+n)%n];ans=min(ans,t+s-a[(i-j+n)%n-1]);
			}
			printf(" %d",ans);
		}
		puts("");
	}
	return 0;
}
