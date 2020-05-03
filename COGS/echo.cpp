#include <cstdio>
#include <cstring>
#define MAXN 100
using namespace std;

char a[MAXN],b[MAXN];
int ans,la,lb,cnt;

inline int mymax(int a,int b){return a>b?a:b;}

int main()
{
    freopen("echo.in","r",stdin);freopen("echo.out","w",stdout);
    scanf("%s",a);scanf("%s",b);
    la=strlen(a);lb=strlen(b);
    for (int i=0;i<la;i++)
        for (int j=lb-1;~j;j--)
        {
            int x=i,y=j;cnt=0;
            while (a[x]==b[y]&&x<la&&y<lb)
            {
                cnt++;x++;y++;
            }
            ans=mymax(ans,cnt);
        }
    printf("%d\n",ans);
    return 0;
}
