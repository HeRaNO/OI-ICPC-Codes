#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string a,b;
int len,pos;
stack <string> s;

int main()
{
    freopen("passworda.in","r",stdin);freopen("passworda.out","w",stdout);
    cin>>a;len=a.size();
    for (int i=0;i<len;i++)
    {
        string pp;pp+=a[i];
        if (pp!="]") s.push(pp);
        else
        {
            string t="",tt="",num="";int cnt=0;
            while (!s.empty()&&(s.top()[0]<'0'||s.top()[0]>'9'))
            {
                t+=s.top();
                s.pop();
            }
            while (!s.empty()&&(s.top()[0]>='0'&&s.top()[0]<='9'))
            {
                num+=s.top()[0];
                s.pop();
            }
            for (int i=num.size()-1;~i;i--) cnt=cnt*10+num[i]-'0';
            s.pop();
            for (int i=1;i<=cnt;i++) s.push(t);
        }
    }
    while (!s.empty())
    {
        b+=s.top();s.pop();
    }
    len=b.size()-1;
    for (int i=len;~i;i--) printf("%c",b[i]);
    puts("");
    return 0;
}
