#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char mi[110],yuan[110], f[110],f2[110],goal[110];
int cnt;
int main(){
    freopen("spy.in","r",stdin);freopen("spy.out","w",stdout);
    scanf("%s%s%s",mi,yuan,goal);
    int len1=strlen(mi),len3=strlen(goal);
    for(int i=0;i<len1;i++){
        if( (!f[mi[i]] && !f2[yuan[i]]) )f[mi[i]]=yuan[i],f2[yuan[i]]=mi[i],cnt++;
        else if( f[mi[i]]==yuan[i] && f2[yuan[i]]) continue;
        else {printf("Failed");exit(0);
    }

    }
    if(cnt!=26) {printf("Failed");exit(0);}
    for(int i=0;i<len3;i++) goal[i]=f[goal[i]];
    printf("%s",goal);
    return 0;
}
