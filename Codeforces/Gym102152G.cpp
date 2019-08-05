#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
const int INF=0x7fffffff;
int num[30];
char  a[50000];
char b[MAXN];
char nn[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",abs(a-c)+abs(b-d));
    }
	return 0;
}