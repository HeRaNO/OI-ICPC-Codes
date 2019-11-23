#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=5e5+10;
const int MOD=1e9+7;
const ll llINF=~(1ll<<63);
const ll mod=998244353;

int mp[2005][2005];
int w,h,n,q;

struct Node
{
	int x,y,w,h;
}e[15];

int idx[15];

int main()
{
	idx[0]=99;
	scanf("%d%d%d",&w,&h,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].w,&e[i].h);
		for(int j=max(e[i].x,0);j<min(h,e[i].x+e[i].h);j++)
			for(int k=max(e[i].y,0);k<min(w,e[i].y+e[i].w);k++)
				if(!mp[j][k])
					mp[j][k]=i;
		idx[i]=i-1;
	}
	scanf("%d",&q);
	for(int kase=1;kase<=q;kase++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int mxidx=mp[x][y];
		if(x&&idx[mxidx]>idx[mp[x-1][y]])
			mxidx=mp[x-1][y];
		if(x&&y&&idx[mxidx]>idx[mp[x-1][y-1]])
			mxidx=mp[x-1][y-1];
		if(y&&idx[mxidx]>idx[mp[x][y-1]])
			mxidx=mp[x][y-1];
		if(!mxidx)
		{
			puts("0");
			continue;
		}
		if(idx[mxidx])
		{
			for(int i=1;i<=n;i++)
			idx[i]++;
			idx[mxidx]=0;
		}
		int ans=0;
		for(int j=max(0,e[mxidx].x);j<min(h,e[mxidx].x+e[mxidx].h);j++)
			for(int k=max(0,e[mxidx].y);k<min(w,e[mxidx].y+e[mxidx].w);k++)
			{
				if(mp[j][k]!=mxidx)ans++;
				mp[j][k]=mxidx;
			}
		printf("%d\n",ans);
	}
	return 0;
}
