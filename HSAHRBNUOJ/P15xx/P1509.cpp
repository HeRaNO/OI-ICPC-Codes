#include <cstdio>
#include <cstring>
#define MAXN 1005
#define MAXP 105
#define MAXK 6
using namespace std;

int n,T,ans;
int ok[MAXN],arr[MAXP],p[MAXP][MAXK][2],c[MAXP],rd[MAXP][MAXK];

inline void read(int &x)
{
	x=0;char ch;
	if ((ch=getchar())==EOF){x=-1;return ;}
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	while (1)
	{
		memset(ok,0,sizeof ok);memset(rd,0,sizeof rd);
		read(T);if (!~T) break;read(n);ans=0;
		for (int i=1;i<=n;i++)
		{
			read(arr[i]);read(c[i]);
			for (int j=1;j<=c[i];j++) read(p[i][j][0]),read(p[i][j][1]);
		}
		for (int nT=0;nT<T;nT++)
			for (int i=1;i<=n;i++)
				if (arr[i]<=nT)
				{
					bool f=false;
					for (int j=1;j<=c[i]&&!f;j++)
						if (ok[p[i][j][0]]<=nT&&!rd[i][j])
						{
							f=true;rd[i][j]=true;++ans;
							ok[p[i][j][0]]=arr[i]=nT+p[i][j][1];
						}
					if (f) continue;
					int m=~(1<<31),pt;
					for (int j=1;j<=c[i];j++)
						if (ok[p[i][j][0]]<m&&!rd[i][j]) m=ok[p[i][j][0]],pt=j;
					if (m>=T) continue;
					rd[i][pt]=true;
					ok[p[i][pt][0]]+=p[i][pt][1];
					arr[i]=ok[p[i][pt][0]];++ans;
				}
		printf("%d\n",ans);
	}
	return 0;
}