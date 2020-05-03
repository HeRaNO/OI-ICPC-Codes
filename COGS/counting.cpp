#include <cstdio>
#include <cstring>
using namespace std;

int s,t,w;
char num[26],l,r;

int main()
{
    freopen("counting.in","r",stdin);freopen("counting.out","w",stdout);
    scanf("%d %d %d",&s,&t,&w);
    scanf("%s",num);
    l=s+'a'-1;r=t+'a'-1;
    for (int i=1;i<=5;i++)
    {
        int j=w-1;
        while (j>=0&&num[j]==r+j-w+1) j--;
        if (j==-1) break;
        num[j]++;
        for (int k=j+1;k<w;k++) num[k]=num[k-1]+1;
        printf("%s\n",num);
    }
    return 0;
}
