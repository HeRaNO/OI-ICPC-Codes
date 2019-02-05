#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=60+5;
const int maxr=60+5;
const int maxnode=60*60+5;
struct DLX{
    int n,sz;
    int S[maxn];
    int row[maxnode],col[maxnode];
    int L[maxnode],R[maxnode],U[maxnode],D[maxnode];
    int ansd,ans[maxr];
    void init(int n){
        this->n=n;
        for(int i=0;i<=n;++i){
            U[i]=i;
            D[i]=i;
            L[i]=i-1;
            R[i]=i+1;
        }
        R[n]=0; L[0]=n;
        sz=n+1; ansd=1000000007;
        memset(S,0,sizeof(S));
    }
    void addRow(int r,vector<int> columns){
        int first=sz;
        for(int i=0;i<columns.size();++i){
            int c=columns[i];
            L[sz]=sz-1;
            R[sz]=sz+1;
            D[sz]=c;
            U[sz]=U[c];
            D[U[c]]=sz;
            U[c]=sz;
            row[sz]=r;
            col[sz]=c;
            ++S[c];
            ++sz;
        }
        R[sz-1]=first;
        L[first]=sz-1;
    }
    #define FOR(i,A,s) for(int i=A[s];i!=s;i=A[i])
    void remove(int c){
        L[R[c]]=L[c];
        R[L[c]]=R[c];
        FOR(i,D,c){
            FOR(j,R,i){
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                --S[col[j]];
            }
        }
    }
    void restore(int c){
        FOR(i,U,c){
            FOR(j,L,i){
                ++S[col[j]];
                U[D[j]]=j;
                D[U[j]]=j;
            }
        }
        L[R[c]]=c;
        R[L[c]]=c;
    }
    bool dfs(int d){
        if(R[0]==0){
            ansd=d;
            return 1;
        }
        int c=R[0];
        FOR(i,R,0){
            if(S[i]<S[c]){
                c=i;
            }
        }
        remove(c);
        FOR(i,D,c){
            ans[d]=row[i];
            FOR(j,R,i){
                remove(col[j]);
            }
            if(dfs(d+1)){
                return 1;
            }
            FOR(j,L,i){
                restore(col[j]);
            }
        }
        restore(c);
        return 0;
    }
    bool solve(vector<int>& v){
        v.clear();
        if(!dfs(0)){
            return 0;
        }
        for(int i=0;i<ansd;++i){
            v.push_back(ans[i]);
        }
        return 1;
    }
     
    void remov2(int c){
        FOR(i,D,c){
            L[R[i]]=L[i];
            R[L[i]]=R[i];
        }
    }
    void restor2(int c){
        FOR(i,U,c){
            L[R[i]]=R[L[i]]=i;
        }
    }
    int f(){
        bool vis[maxn];
        int res=0;
        FOR(i,R,0){
            vis[i]=1;
        }
        FOR(i,R,0){
            if(vis[i]){
                ++res;
                vis[i]=0;
                FOR(j,D,i){
                    FOR(k,R,j){
                        vis[col[k]]=0;
                    }
                }
            }
        }
        return res;
    }
    void df2(int d){
        if(d+f()>=ansd){
            return;
        }
        if(R[0]==0){
            ansd=min(ansd,d);
            return;
        }
        int c=R[0];
        FOR(i,R,0){
            if(S[i]<S[c]){
                c=i;
            }
        }
        FOR(i,D,c){
            remov2(i);
            FOR(j,R,i){
                remov2(j);
            }
            df2(d+1);
            FOR(j,L,i){
                restor2(j);
            }
            restor2(i);
        }
    }
     
}dlx;
int n,m;
bool a[60][60];
int main(){
    int x,y;
    while(scanf("%d%d",&n,&m)!=EOF){
        dlx.init(n);
        memset(a,0,sizeof(a));
        for(int i=1;i<=m;++i){
            scanf("%d",&x);
            for (int j=1;j<=x;j++) scanf("%d",&y),a[i][y]=1;
        }
        for(int i=1;i<=n;++i){
            vector<int> columns;
            for(int j=1;j<=n;++j){
                if(a[i][j]){
                    columns.push_back(j);
                }
            }
            if(!columns.empty()){
                dlx.addRow(i,columns);
            }
        }
        dlx.df2(0);
        printf("%d\n",dlx.ansd);
    }
    return 0;
}