#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const db Pi=acos(-1);

int t, n;
int a[55];
int dp[2005];
bool path[55][2005];
bool vis[55];
int main() {
    while (scanf("%d", &t)==1 && t) {
        scanf("%d", &n);
        for (int i = n; i > 0; --i) scanf("%d", a + i);
        memset(dp, 0, sizeof dp);
        memset(path, false, sizeof path);
        memset(vis, false, sizeof vis);
        for (int i = 1; i <= n; ++i) {
            for (int j = t; j >= a[i]; --j) {
                if (dp[j] <= dp[j - a[i]] + a[i]) {
                    dp[j] = dp[j - a[i]] + a[i];
                    path[i][j] = true;
                }
            }
        }
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 0; j <= t; ++j) {
        //         printf("%d ", path[i][j]);
        //     }
        //     puts("");
        // }
        int i = n;
        int tot = 0;
        for (int j = t; i > 0&&j>0;) {
            while (!path[i][j]&&i>0) --i;
            vis[i] = 1;
            j -= a[i];
            tot += a[i];
            i--;
        }
        for (int i = n; i > 0; --i)
            if (vis[i]) printf("%d ", a[i]);
        printf("%d\n", tot);
    }
    return 0;
}