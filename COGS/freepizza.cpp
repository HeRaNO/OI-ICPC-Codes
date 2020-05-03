#include <iostream>
#include <cstdio>
#define INF 9999999
using namespace std;
int w,h;
int dp[1001][101];
int sel[1001][101];
int mat[1001][101];
void PrintAns(int Floor,int Pos)
{
    if(Floor<1) return;
    PrintAns(Floor-1,Pos-sel[Floor][Pos]);
    printf("%d\n",sel[Floor][Pos]);
}
int main()
{
    freopen("freepizza.in","r",stdin);
    freopen("freepizza.out","w",stdout);
    scanf("%d%d",&w,&h);
    int cnt=0;
    int s,pos,v,grade;
    int lasts=0;
    while(scanf("%d%d%d%d",&s,&pos,&v,&grade)==4)
    {
        if((h-1)%v==0 || s==0)
        {
            mat[s+(h-1)/v][pos]+=grade;
            lasts=max(lasts,s+(h-1)/v);
            cnt++;
        }
    }
    if(!cnt)
    {
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=w;i++)
        dp[0][i]=-INF;
    dp[0][w/2+1]=mat[0][w/2+1];
    for(int i=1;i<=lasts;i++)
    {
        for(int j=1;j<=w;j++)
        {
            int maxx=-INF;
            if(j>=3)
            {
                if(maxx<dp[i-1][j-2])
                {
                    maxx=dp[i-1][j-2];
                    sel[i][j]=2;
                }
            }
            if(j>=2)
            {
                if(maxx<dp[i-1][j-1])
                {
                    maxx=dp[i-1][j-1];
                    sel[i][j]=1;
                }
            }
            if(maxx<dp[i-1][j])
            {
                maxx=dp[i-1][j];
                sel[i][j]=0;
            }
            if(j<=w-1)
            {
                if(maxx<dp[i-1][j+1])
                {
                    maxx=dp[i-1][j+1];
                    sel[i][j]=-1;
                }
            }
            if(j<=w-2)
            {
                if(maxx<dp[i-1][j+2])
                {
                    maxx=dp[i-1][j+2];
                    sel[i][j]=-2;
                }
            }
            dp[i][j]=maxx+mat[i][j];
        }
    }
    int maxi;
    int maxx=-INF;
    for(int i=1;i<=w;i++)
    {
        if(maxx<dp[lasts][i])
        {
            maxx=dp[lasts][i];
            maxi=i;
        }
    }
    printf("%d\n",maxx);
    PrintAns(lasts,maxi);
    if(lasts==0)
    printf("0\n");
    return 0;
}
