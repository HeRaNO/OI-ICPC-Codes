#include <cstdio>
#include <algorithm>
#define MAXN 1000010
using namespace std;

pair <int,int> a[MAXN];
int n,cnt,ans,x0,y0,xt,yt,dx,dy;

inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	x*=f;return ;
}

int main()
{
    freopen("loverfinding.in","r",stdin);freopen("loverfinding.out","w",stdout);
    read(n);read(x0);read(y0);read(xt);read(yt);
    a[++cnt]=make_pair(x0,y0);
    while (n--)
    {
        read(dx);read(dy);
        x0+=dx;y0+=dy;
        a[++cnt]=make_pair(x0,y0);
        if (x0==xt&&y0==yt)
        {
            sort(a+1,a+cnt+1);
            ans=unique(a+1,a+cnt+1)-a-1;
            printf("%d\n",ans);
            return 0;
        }
    }
    puts("SingleDogMZX");
    return 0;
}
