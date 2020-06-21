#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=1e3+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int p[5];
char s[MAXN];
int g[50][50];
int main()
{
    for(int i=1;i<=5;i++)
    {
        scanf("%s",s);
        int u=s[0]-'A';
        int v=s[2]-'A';
        if(s[1]=='<')g[u][v]=1;
        else g[v][u]=1;
    }
    for(int i=0;i<5;i++)p[i]=i;
    do
    {
        bool f=0;
        for(int i=0;i<5;i++)
            for(int j=i+1;j<5;j++)
            if(g[p[j]][p[i]])f=1;
        if(!f)
        {
            for(int i=0;i<5;i++)putchar(p[i]+'A');puts("");
            return 0;
        }
    }while(next_permutation(p,p+5));
    puts("impossible");
    return 0;
}