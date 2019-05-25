#include <bits/stdc++.h>
#define MAXN 85
#define MAXT 700
#define MAXS 391000
using namespace std;

char s[MAXN];
int n,m,x,a[MAXN][MAXN],p[MAXN],b[MAXN],pt[MAXN][MAXN],ppt;
int dp[MAXN][MAXT],_5[MAXT],h[MAXS],cnt,ans=~(1<<31);
int mp[3][MAXN],d[MAXN];

void flood(int x,int y,int id)
{
	if (x<1||x>n||y<1||y>m||pt[x][y]>=id) return ;
	pt[x][y]=id;
	if (!a[x-1][y]) flood(x-1,y,id);
	if (!a[x+1][y]) flood(x+1,y,id);
	if (!a[x][y-1]) flood(x,y-1,id);
	if (!a[x][y+1]) flood(x,y+1,id);
	return ;
}

inline void make_table()
{
	int kk=1;
	for (int i=1;i<=m;i++) kk=kk*5;
	for (int sta=0;sta<kk;sta++)
	{
		int x=sta,pre=0;bool f=true;
		for (int i=m;i;i--,x/=5) b[i]=x%5;
		for (int i=1;i<=m&&f;i++)
			if (b[i])
			{
				if (!(b[i]==pre||b[i]==pre+1)) f=false;
				while (b[i+1]&&f)
				{
					if (b[i+1]==b[i]) i++;
					else f=false;
				}
				pre=b[i];
			}
		if (f) _5[++cnt]=sta;
	}
	for (int i=1;i<=cnt;i++) h[_5[i]]=i;
	return ;
}

inline int f(int x)
{
	int res=0;
	for (int i=1;i<=m;i++,x>>=1) b[i]=-(x&1);
	int i=1,pt=0;
	while (!~b[i]) i++;
	for (;i<=m;)
	{
		++pt;
		while (!b[i]&&i<=m) b[i]=pt,++i;
		while (!~b[i]&&i<=m) ++i;
	}
	for (int i=1;i<=m;i++) res=res*5+(b[i]==-1?0:b[i]);
	return res;
}

inline int check(int blas,int las,int ths)
{
	int mx=0,res=0,l=0,pt=1;memset(d,0,sizeof d);memset(b,0,sizeof b);
	for (int i=1;i<=m;i++,blas>>=1) mp[0][i]=blas&1;
	for (int i=m;i;i--,las/=5) mp[1][i]=las%5,mx=max(mx,las%5);
	for (int i=1;i<=m;i++,ths>>=1) mp[2][i]=ths&1;
	for (int i=1;i<=m;i++) if (!mp[0][i]&&!mp[1][i]) return -1;
	for (int i=1;i<=m;i++)
	{
		if (!mp[2][i])
		{
			if (!l) l=i;
			if (!mp[1][i]) continue;
			if (mp[1][i]>1&&!d[mp[1][i]-1]) return -1;
			if (d[mp[1][i]]) pt=d[mp[1][i]];
			else d[mp[1][i]]=pt;
		}
		else
		{
			if (!l) continue;
			for (int j=l;j<i;j++) b[j]=pt;
			++pt;l=0;
		}
	}
	if (l)
	{
		for (int i=l;i<=m;i++) b[i]=pt;
	}
	for (int i=1;i<=mx;i++) if (!d[i]) return -1;
	for (int i=1;i<=m;i++) res=res*5+b[i];
	return res;
}

inline bool ok(int blas,int las)
{
	for (int i=1;i<=m;i++,blas>>=1) mp[0][i]=blas&1;
	for (int i=m;i;i--,las/=5) d[i]=las%5,mp[1][i]=1-(las%5!=0);
	for (int i=1;i<=m;i++) if (d[i]>1) return false;
	for (int i=1;i<=m;i++) if (mp[0][i]==0&&mp[1][i]==1) return false;
	return true;
}

int main()
{
	scanf("%d %d",&n,&m);memset(dp,0x3f,sizeof dp);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=1;j<=m;j++) a[i][j]=s[j-1]-'0';
	}
	if (n<m)
	{
		for (int i=1;i<=m;i++)
			for (int j=1;j<i;j++)
				swap(a[i][j],a[j][i]);
		swap(n,m);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			p[i]|=a[i][j]<<(j-1);
			if (!a[i][j]&&(!pt[i][j]||pt[i][j]>ppt))
				flood(i,j,++ppt);
		}
	if (ppt<=1) return puts("0"),0;
	make_table();int srt=0,ed=0;
	for (int i=1;i<=n&&!srt;i++) if (p[i]!=(1<<m)-1) srt=i;
	for (int i=n;i&&!ed;i--) if (p[i]!=(1<<m)-1) ed=i;
	for (int i=p[srt];i;i=(i-1)&p[srt]) dp[srt][h[f(i)]]=__builtin_popcount(p[srt]^i);
	dp[srt][h[f(0)]]=__builtin_popcount(p[srt]);
	for (int i=srt;i<ed;i++)
		for (int j=1;j<=cnt;j++)
		{
			if (dp[i][j]==0x3f3f3f3f) continue;int sta;
			for (int k=p[i+1];k;k=(k-1)&p[i+1])
			{
				sta=check(p[i],_5[j],k);
				if (~sta)
					dp[i+1][h[sta]]=min(dp[i+1][h[sta]],dp[i][j]+__builtin_popcount(p[i+1]^k));
			}
			sta=check(p[i],_5[j],0);
			if (~sta)
				dp[i+1][h[sta]]=min(dp[i+1][h[sta]],dp[i][j]+__builtin_popcount(p[i+1]));
		}
	for (int i=1;i<=cnt;i++) if (ok(p[ed],_5[i])) ans=min(ans,dp[ed][i]);
	printf("%d\n",ans);
	return 0;
}
