#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <string.h>
#define MAXN 10001
using namespace std;

int n,i,j;
int ans;
int si;
stack <string> s;
string word[MAXN];

int mymin(int a,int b)
{
    return a<b?a:b;
}

int mymax(int a,int b)
{
    return a>b?a:b;
}

bool cmp (string a,string b)
{
    for (int i=0;i<b.size();i++)
    {
        if (a[i]!=b[i]) return false;
    }
    return true;
}

int main()
{
    freopen("link.in","r",stdin);freopen("link.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        cin>>word[i];
    for (i=1;i<=n;i++)
    {
        ans=mymax(ans,s.size());
        if (s.empty())
        {
            s.push(word[i]);
            continue;
        }
        if (cmp(word[i],s.top()))
        {
            s.push(word[i]);
            continue;
        }
        else
        {
            while (!s.empty())
            {
                s.pop();
                if (cmp(word[i],s.top())||s.empty())
                {
                    s.push(word[i]);
                    break;
                }
            }
        }
        ans=mymax(ans,s.size());
    }
    ans=mymax(ans,s.size());
    printf("%d",ans);
    return 0;
}
