#include <bits/stdc++.h>
#define MAXN 100005
#define MAXB 320
using namespace std;

int n,m,k,T,o,l,r,v,w,cnt[MAXB][MAXN],pos[MAXN];
int d[MAXB],a[MAXN];

inline void fadd(int &x,int y){x+=y;if (x>=k) x-=k;return ;}

inline void init(int x)
{
	int l=(x-1)*m+1,r=x*m;
	for (int i=l;i<=r&&i<=n;i++) ++cnt[x][a[i]];
	return ;
}

inline int query(int l,int r,int v,int w)
{
	int res=0;
	if (pos[l]==pos[r])
	{
		int x=pos[l],y=v-d[x];if (y<0) y+=k;
		for (int i=l;i<=r;i++)
		{
			res+=(a[i]==y);
			--cnt[x][a[i]];
			fadd(a[i],w);
			++cnt[x][a[i]];
		}
		return res;
	}
	int x=pos[l],y=v-d[x];if (y<0) y+=k;
	for (int i=l,p=pos[l]*m;i<=p;i++)
	{
		res+=(a[i]==y);
		--cnt[x][a[i]];
		fadd(a[i],w);
		++cnt[x][a[i]];
	}
	for (int i=pos[l]+1;i<pos[r];i++)
	{
		y=v-d[i];if (y<0) y+=k;
		res+=cnt[i][y];fadd(d[i],w);
	}
	x=pos[r];y=v-d[x];if (y<0) y+=k;
	for (int i=(pos[r]-1)*m+1;i<=r;i++)
	{
		res+=(a[i]==y);
		--cnt[x][a[i]];
		fadd(a[i],w);
		++cnt[x][a[i]];
	}
	return res;
}

inline void read(int &x)
{
	x=0;bool f=false;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);read(k);m=(int)sqrt(n);
	for (int i=1;i<=n;i++)
	{
		read(a[i]);a[i]%=k;if (a[i]<0) a[i]+=k;
		pos[i]=(i-1)/m+1;
	}
	for (int i=1;i<=pos[n];i++) init(i);
	read(T);
	while (T--)
	{
		read(l);read(r);read(v);read(w);
		v%=k;if (v<0) v+=k;
		w%=k;if (w<0) w+=k;
		printf("%d\n",query(l,r,v,w));
	}
	return 0;
}