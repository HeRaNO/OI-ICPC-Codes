#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
#define MAXL 5010
using namespace std;
 
struct game
{
    int left;
    int right;
};
 
int n;
game a[MAXN],king;
int now[MAXL],ans[MAXL],maxc[MAXL];
int len;
 
void multiply(int x)
{
    int jin=0,i;
    for (i=1;i<=len;i++)
    {
        now[i]=now[i]*x+jin;
        jin=now[i]/10;
        now[i]%=10;
    }
    while (jin)
    {
        now[i]+=jin;
        jin=now[i]/10;
        now[i]%=10;
        i++;
    }
    len=i-1;
    return ;
}
 
void division(int x)
{
    int i,jin=0;
    memset(ans,0,sizeof(ans));
    for (int i=len;i;i--)
    {
        ans[i]=(jin*10+now[i])/x;
        jin=(jin*10+now[i])%x;
    }
    return ;
}
 
void compare()
{
    for (int i=len;i;i--)
    {
        if (maxc[i]<ans[i])
        {
            memcpy(maxc,ans,sizeof(ans));
            return ;
        }
        else if (maxc[i]>ans[i]) return ;
    }
}
 
bool cmp(game a,game b)
{
    return a.left*a.right<b.left*b.right;
}
 
int main()
{
freopen("kinggame.in","r",stdin);freopen("kinggame.out","w",stdout);
    scanf("%d",&n);
    scanf("%d %d",&king.left,&king.right);
    for (int i=1;i<=n;i++)
        scanf("%d %d",&a[i].left,&a[i].right);
    sort(a+1,a+n+1,cmp);
    while (king.left)
    {
        len++;
        now[len]=king.left%10;
        king.left/=10;
    }
    for (int i=1;i<=n;i++)
    {
        division(a[i].right);
        compare();
        multiply(a[i].left);
    }
    len=5000;
    while(!maxc[len]) len--;
    for (int i=len;i;i--) printf("%d",maxc[i]);
    printf("\n");
    return 0;
}
