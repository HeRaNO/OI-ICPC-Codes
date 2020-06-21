#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int n,k,e;
int ok[2005][2005];
ll dp[2005][1<<9];

int main()
{
    scanf("%d%d%d",&n,&e,&k);
    for(int i=1;i<=k;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ok[u][v]=1;
    }
    dp[0][0]=1;
    int p=e*2+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(1<<p);j++)
        {
            for(int k=0;k<p;k++)
            if(((j>>1)&(1<<k))==0&&!ok[i][i+k-e]&&i+k-e>=1)
            {
                (dp[i][(j>>1)|(1<<k)]+=dp[i-1][j])%=MOD;
            }
        }
    }
    cout<<dp[n][(1<<(e+1))-1];
    return 0;
}