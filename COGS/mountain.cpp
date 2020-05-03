#include <cstdio>
#include <algorithm>
using namespace std;
 
long long n,d,a,b,tmp;
 
int main()
{
    freopen("mountain.in","r",stdin);freopen("mountain.out","w",stdout);
    scanf("%lld %lld %lld %lld",&n,&d,&a,&b);n--;
    if (a>b) swap(a,b);
    tmp=(b-a)/d+1LL;
    if ((b-a)%d==0LL) tmp--;
    n-=tmp;
    if (n%2LL==0LL)
        printf("%lld\n",(n/2LL)*d+b);
    else
    {
        tmp=tmp*d+a;
        printf("%lld\n",(n/2LL)*d+tmp);
    }
    return 0;
}
