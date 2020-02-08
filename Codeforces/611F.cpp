#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=8e5+10,MAXM=4e6+20;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=119;
const int Lim=1<<20;

const int may=1e6+10;
int n,h,w;
char s[MAXN];
int xx[MAXM],yy[MAXM],mxdx,mxdy,midx,midy;

pii mov(int u)
{
	if(s[u]=='U')return {0,1};
	if(s[u]=='D')return {0,-1};
	if(s[u]=='R')return {1,0};
	if(s[u]=='L')return {-1,0};
	return {0,0};
}

vector<ll> yes;

int main()
{
	int dx=0,dy=0;
	bool ok=1;
	cin>>n>>h>>w;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		tie(x,y)=mov(i);
		dx+=x;
		dy+=y;
		if(dx>mxdx)xx[dx+may]=i,mxdx=dx;
		if(dx<midx)xx[dx+may]=i,midx=dx;
		if(dy>mxdy)yy[dy+may]=i,mxdy=dy;
		if(dy<midy)yy[dy+may]=i,midy=dy;
		if(abs(dx)>=w||abs(dy)>=h)ok=0;
	}
	if(ok&&!dx&&!dy)return puts("-1"),0;
	ll ans=0,l=1,r=w,u=h,d=1,t=1;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		tie(x,y)=mov(i);
		l+=x;r+=x;u+=y;d+=y;
		if(l<1)(ans+=(ll)(u-d+1)*i%MOD)%=MOD,l++;
		if(r>w)(ans+=(ll)(u-d+1)*i%MOD)%=MOD,r--;
		if(d<1)(ans+=(ll)(r-l+1)*i%MOD)%=MOD,d++;
		if(u>h)(ans+=(ll)(r-l+1)*i%MOD)%=MOD,u--;
		if(l>r||u<d)break;
	}
	if(dx>0) for(int i=mxdx-dx+1;i<=mxdx;i++)yes.push_back(xx[i+may]);
	if(dx<0) for(int i=midx-dx-1;i>=midx;i--)yes.push_back(xx[i+may]);
	if(dy>0) for(int i=mxdy-dy+1;i<=mxdy;i++)yes.push_back(yy[i+may]);
	if(dy<0) for(int i=midy-dy-1;i>=midy;i--)yes.push_back(yy[i+may]);
	sort(yes.begin(),yes.end());
	while(l<=r&&d<=u)
	{
		for(auto i:yes)
		{
			int x,y;
			tie(x,y)=mov(i);
			if(x<0)(ans+=(ll)(u-d+1)*(i+t*n)%MOD)%=MOD,l++;
			if(x>0)(ans+=(ll)(u-d+1)*(i+t*n)%MOD)%=MOD,r--;
			if(y<0)(ans+=(ll)(r-l+1)*(i+t*n)%MOD)%=MOD,d++;
			if(y>0)(ans+=(ll)(r-l+1)*(i+t*n)%MOD)%=MOD,u--;
			if(l>r||u<d)break;
		}
		t++;
	}
	cout<<ans;
	return 0;
}
