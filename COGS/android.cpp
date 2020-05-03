#include <cstdio>
#include <cstring>
#define MAXN 5010
using namespace std;

char seq[MAXN];
int n,T,x,y;
int lft,p;

int main()
{
    freopen("android.in","r",stdin);freopen("android.out","w",stdout);
    scanf("%s",seq+1);scanf("%d",&T);
    n=strlen(seq+1);
    if (T<=n)
    {
        for (int i=1;i<=T;i++)
        {
            if (seq[i]=='E') x++;
            else if (seq[i]=='S') y--;
            else if (seq[i]=='W') x--;
            else y++;
        }
        printf("%d %d\n",x,y);
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        if (seq[i]=='E') x++;
        else if (seq[i]=='S') y--;
        else if (seq[i]=='W') x--;
        else y++;
    }
    p=T/n;lft=T%n;
    x*=p;y*=p;
    for (int i=1;i<=lft;i++)
    {
        if (seq[i]=='E') x++;
        else if (seq[i]=='S') y--;
        else if (seq[i]=='W') x--;
        else y++;
    }
    printf("%d %d\n",x,y);
    return 0;
}
