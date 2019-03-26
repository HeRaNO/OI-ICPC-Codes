#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define MOD 163577857
#define MAX 1000005
#define ll long long
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)

using namespace std;

ll power(ll a,ll b,ll m){
	ll x=1%m; a%=m;
	while(b){
		if((1&b)) x = x * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return x;
}

int mul(const int &a,const int &b){
	ll ans = a*1LL*b;
	if(ans>=MOD) return ans%MOD;
	return ans;
}

// NTT helper
const int mod = 163577857;
const int root = 40336560;	// g^((mod-1)/root_pw)
const int root_1 = 3509831;
const int LG = 21;
const int root_pw = 1<<21;

int copyA[root_pw],rev[root_pw],invW[root_pw>>1],W[root_pw>>1];
void precompute_powers(){
	W[0] = invW[0] = 1;
	for(int i = 1;i<(root_pw>>1);i++){
        W[i] = mul(W[i-1],root);
        invW[i] = mul(invW[i-1],root_1);
    }
    int k = 0; while ((1 << k) < root_pw) ++k;
    rev[0] = 0;
    for (int i = 1; i < root_pw; i++) {
        rev[i] = rev[i >> 1] >> 1 | ((i & 1) << k - 1);
    }
}
void ntt (int* a,const int &n,const bool &invert) {
    memcpy(copyA,a,n*sizeof(int));
    int k = 0; while ((1 << k) < n) ++k;
    for (int i = 0; i < n; i++) {
        a[i] = copyA[rev[i] >> (LG - k)];
    }
    int * mkb = invert?invW:W;
    int prev_len = 1, u,v,len,i,ind,add,j;
 	for (len=2; len<=n; len<<=1) {
        for (i=0; i<n; i+=len) {
            ind = 0,add = root_pw/len;
            for (j=0; j<prev_len; ++j) {
                u = a[i+j],  v = mul(a[i+j+prev_len],mkb[ind]);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+prev_len] = u-v >= 0 ? u-v : u-v+mod;
                ind += add;
            }
        }
        prev_len = len;
    }
	if (invert) {
		int nrev = power(n, mod-2,mod);
		for (int i=0; i<n; ++i)
			a[i] = mul(a[i],nrev);
	}
}
void mul(int *a,const int &n1,int *b,const int &n2){
	int n = n1 + n2 - 1, i;
	int m = 1; while(m<n) m<<=1;
	for(i=n1;i<m;++i) a[i]=0;
	for(i=n2;i<m;++i) b[i]=0;
	ntt(a,m,0);ntt(b,m,0);
	for(i=0;i<m;++i) a[i]=mul(a[i],b[i]);
	ntt(a,m,1);
}
// ENDS

// Combinatorics
int fact[MAX],inverse[MAX],fact_inverse[MAX];

void precalc(){
	fact[0]=1;
	
	inverse[0]=1;inverse[1]=1;
	
	fact_inverse[0]=1;fact_inverse[1]=1;
	
	for(int i=1;i<MAX;i++)
		fact[i]=mul(i,fact[i-1]);
		
	for(int i=2;i<MAX;i++){
		inverse[i]=(MOD-mul(MOD/i,inverse[MOD % i]))%MOD;
		fact_inverse[i]=mul(inverse[i],fact_inverse[i-1]);
	}
}
 
inline int choose(const int &n,const int &r){
	return mul(fact[n],mul(fact_inverse[r],fact_inverse[n-r]));
}
// Ends

// finding (x+1)(x+2)(x+3)...(x+n) in O(nlogn)
// coefficients are stored in cur[i]
int dig[23];
int cur[root_pw];
int polyA[root_pw],polyB[root_pw];
 
void doit(int n){
	int ptr = 0;
	while(n){
		dig[ptr++] = (n&1);
		n >>= 1;
	}
	// lets represent f_n(x) = (x+1)(x+2)...(x+n)
	n = 1;	// start with (x+1)
	cur[0]=cur[1]=1;
	for(int j=ptr-2;j>=0;j--){
		
		// f_2n(x) = f_n(x) * f_n(x+n)
		// finding f_n(x+n)
		for(int i=0;i<=n;i++) polyA[i]=mul(cur[n-i],fact[n-i]);
		int pw = 1;
		for(int i=0;i<=n;i++){
			polyB[i]=mul(pw,fact_inverse[i]);	
			pw = mul(pw,n);
		}
		mul(polyB,n+1,polyA,n+1);
		for(int i=0;i<=n;i++){
			polyA[i]=mul(polyB[n-i],fact_inverse[i]);
		}
		// ends
 
		mul(cur,n+1,polyA,n+1);
 
		n<<=1; 
		
		if(dig[j]){
			// find f_(n+1)(x) given f_n(x)
			for(int i=n+1;i>0;i--) cur[i]=cur[i-1];
			cur[0]=0;
			n += 1;
			for(int i=0;i<n;i++){
				cur[i]+=mul(cur[i+1],n);
				if(cur[i]>=mod) cur[i]-=mod;
			}
		}
	}
}
// ends

int solve(int n,int k){
	doit(n);
	int ans = 0;
	for(int r=1;r<=k;r++){
		ans += mul(choose(k-1,r-1),cur[n-r]);
		if(ans>=MOD) ans-=MOD;
	}
	return ans;
}

int main(){
	precompute_powers();
	precalc();
	int t;sd(t);
	while(t--){
		int n,k;
		sd(n);sd(k);
		int ans = solve(n,k);
		pd(ans);
	}
}
