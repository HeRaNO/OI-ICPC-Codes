#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1050;
int n;
char a[N][N],b[N][N];
char op[105];
int L,R;
int dir;
void printb()
{
    for(int i=1;i<=n;++i)
        printf("%s\n",b[i]+1);
}

void solve0()
{
    for(int i=1;i<=n;++i)
        printf("%s\n",a[i]+1);
}

void solve2()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int di=n-i+1,dj=n-j+1;
            if(a[i][j]=='.')b[di][dj]='.';
            else if(a[i][j]=='<')b[di][dj]='>';
            else if(a[i][j]=='>')b[di][dj]='<';
            else if(a[i][j]=='^')b[di][dj]='v';
            else if(a[i][j]=='v')b[di][dj]='^';
        }
    }
    printb();
}
void solve3()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int di=j,dj=n-i+1;
            if(a[i][j]=='.')b[di][dj]='.';
            else if(a[i][j]=='<')b[di][dj]='^';
            else if(a[i][j]=='>')b[di][dj]='v';
            else if(a[i][j]=='^')b[di][dj]='>';
            else if(a[i][j]=='v')b[di][dj]='<';
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            a[i][j]=b[i][j];
}

int main()
{
    cin>>n;
    scanf("%s",op+1);
    for(int i=1;i<=n;++i)
        scanf("%s",a[i]+1);
    for(int i=1;op[i];++i)
        if(op[i]=='L')L++;else R++;
    if(L>R){int t=L-R;dir=t%4;}
    else if(L==R)dir=0;
    else if(L<R){int t=R-L;dir=(4-t%4)%4;}
    switch(dir)
    {
        case 0:solve0();break;
        case 1:solve3(),solve3(),solve3(),printb();break;
        case 2:solve2();break;
        case 3:solve3(),printb();break;
    }
    return 0;
}