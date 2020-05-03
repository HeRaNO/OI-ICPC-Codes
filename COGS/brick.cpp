#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
string a[1010];

bool cmp(string a,string b)
{
    return a+b>b+a;
}

int main()
{
    freopen("brick.in","r",stdin);freopen("brick.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++) cout<<a[i];
    return 0;
}
