#include <cstdio>
#define MAXN 200020
using namespace std;

int a[MAXN];
int n;
int last,ans;
int start;

int mymax(int a,int b)
{
    return a>b?a:b;
}

int mymin(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    freopen("maxsum.in","r",stdin);freopen("maxsum.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[n+i]=a[i];
    }
    for (int i=1;i<=n;i++)
    {
        last=mymin(0,last)+a[i];
        if (ans>last)
        {
            start=i;
            ans=last;
        }
    }
    ans=0;last=0;
    for (int i=1+start;i<=n+start;i++)
    {
        last=mymax(0,last)+a[i];
        ans=mymax(ans,last);
    }
    printf("%d",ans);
    return 0;
}
