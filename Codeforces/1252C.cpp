#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e5+10,MAXM=2e7+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

int n,m;
int r[MAXN],c[MAXN];
int er[MAXN],ec[MAXN],odr[MAXN],oc[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&r[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)er[i]=er[i-1]+(r[i]%2==0),odr[i]=odr[i-1]+r[i]%2;
	for(int i=1;i<=n;i++)ec[i]=ec[i-1]+(c[i]%2==0),oc[i]=oc[i-1]+c[i]%2;
	for(int i=1;i<=m;i++)
	{
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1>x2)swap(x1,x2);
		if(y1>y2)swap(y1,y2);
		bool f=0,g=0;
		if(odr[x2]-odr[x1-1]==0||er[x2]-er[x1-1]==0)f=1;
		if(oc[y2]-oc[y1-1]==0||ec[y2]-ec[y1-1]==0)g=1;
		if(f&&g)puts("YES");
		else puts("NO");
	}
	return 0;
}
