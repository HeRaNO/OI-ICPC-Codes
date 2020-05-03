#include <map>
#include <vector>
#include <cstdio>
using namespace std;

int n,m,x,y;
map <int,vector<int> > a;

int main()
{
    freopen("2333_.in","r",stdin);freopen("2333_.out","w",stdout);
    while (~scanf("%d %d",&n,&m))
    {
        a.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if (!a.count(x)) a[x]=vector<int>();
            a[x].push_back(i);
        }
        while (m--)
        {
            scanf("%d %d",&x,&y);
            if (!a.count(y)||a[y].size()<x) printf("0\n");
            else printf("%d\n",a[y][x-1]);
        }
    }
    return 0;
}
