#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=1050;
double p[N][N];
int n;
double dp[N],ji[N];
bool vis[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
    {
        int x;cin>>x;
        p[i][j]=x/100.0;
    }
    if(n==1)return puts("0"),0;
    for(int i=1;i<=n;++i)dp[i]=1.0,ji[i]=1.0-p[i][n];
    dp[n]=0;vis[n]=1;
    for(int i=1;i<=n;++i)
    {
        int now=0;
        double mn=2e18;
        for(int j=1;j<=n;++j)
        {
            if(!vis[j]&&dp[j]/(1.0-ji[j])<mn)
            {
                mn=dp[j]/(1.0-ji[j]);
                now=j;
            }
        }
        vis[now]=1;
        if(now==1)return printf("%.12lf\n",dp[1]/(1.0-ji[1])),0;
        for(int j=1;j<=n;++j)
        {
            dp[j]+=dp[now]*p[j][now]*ji[j]/(1.0-ji[now]);
            ji[j]=ji[j]*(1.0-p[j][now]);
        }
    }
    return 0;
}
