/*
  Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 21/02/2018
time  : 00:20:29
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      sz(v)             (int)(v.size())
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      all(v)            v.begin(), v.end()
#define      scan(n)           scanf("%d", &n)
#define      scan2(n, m)       scanf("%d%d", &n, &m)
#define      pin(n)            printf("%d\n",n)
#define      pis(n)            printf("%d ",n)
#define      pll(n)            printf("%lld\n", n)
#define      X                 first
#define      Y                 second

typedef long long ll;
typedef unsigned long long ull;

// #define int unsigned int

const ull mod = 163577857;

inline int pow_(ll a, int n, int p=mod){
int r=1;while(n){if(n&1)r=r*a%p;n>>=1;a=a*a%p;}return r;}
inline int inv_(int a) {return pow_(a, mod-2, mod);}
inline int add(int a, int b){a+=b;if(a>=mod)a-=mod;return a;}
inline void adds(int& a, int b){a+=b;if(a>=mod)a-=mod;}
inline int mul(int a, ull b){return b*a%mod;}
inline void muls(int& a, ull b){a=b*a%mod;}
inline int sub(int a, int b){a-=b;if(a<0)a+=mod;return a;}
// inline int sub(int a, int b){return a>=b?a-b:a+mod-b;}

int fact[1<<20];
int factInv[1<<20];
int loG2[(1<<20)|1];
int W[1<<20];
int W1[1<<20];

void init() {
	int n = (1<<20)-1;
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = mul(fact[i-1], i);
	factInv[n] = inv_(fact[n]);
	for(int i = n; i>0; --i) factInv[i-1] = mul(factInv[i], i);
	for (int i = 0; i <= 20; ++i) loG2[1<<i] = i;
	for (int i = n; i > 1; --i) if (!loG2[i]) loG2[i] = loG2[i+1];
}

inline int ncr(int n, int r) {
	if(r < 0 || n < r) return 0;
	return mul(fact[n], mul(factInv[n-r], factInv[r]));
}

int * ww;

inline void ntt(int * a, int n, int jump)
{
	for (int i = 1, j = 0; i < n; i++)
	{
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	jump <<= loG2[n>>1];
	for (int len = 2; len <= n; len <<= 1, jump >>= 1)
	{
		for (int i = 0; i < n; i += len)
		{
			int ii=i+len/2, v = a[ii]; a[ii] = sub(a[i], v); adds(a[i],v);
			for (int j = 1, ci = jump, ii = i+len/2; j < len/2; j++, ci += jump)
			{
				v = ww[ci]; muls(v, a[ii+j]);
				a[ii+j] = sub(a[i+j], v);
				adds(a[i+j], v);
			}
		}
	}
}

inline void ntt3(int a[][3], int n, int jump) {
	for (int i = 1, j = 0; i < n; i++)
	{
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) {
			rep(k, 3)swap(a[i][k], a[j][k]);
		}
	}
	jump <<= loG2[n>>1];
	for (int len = 2; len <= n; len <<= 1, jump >>= 1)
	{
		for (int i = 0; i < n; i += len)
		{
			int ii = i + len/2, v;
			rep(k, 3) {
				v = a[ii][k]; a[ii][k] = sub(a[i][k], v); adds(a[i][k],v);
			}
			for (int j = 1, ci = jump; j < len/2; j++, ci += jump)
			{
				rep(k, 3){
					v = ww[ci]; muls(v, a[ii+j][k]);
					a[ii+j][k] = sub(a[i+j][k], v);
					adds(a[i+j][k], v);
				}
			}
		}
	}
}

inline void ntti(int * ar, int n, int jump) {
	ww = W1;
	ntt(ar, n, jump);
	ww = W;
}

int g = 5;

int sTmp[1<<20];
int sTmp1[1<<20];
int sT[1<<20][3];

int tom = 1;
void solve(int n, int * res, int jump) {
	if (n == 0) {
		res[0] = 1;
		return ;
	}
	if (n&1) {
		solve(n-1, res, jump);
		for (int i = n; i > 0; --i) {
			muls(res[i], n);
			adds(res[i], res[i-1]);
		}
		muls(res[0], n);
		return ;
	}
	int n2 = n >> 1, N = 1 << loG2[n + 1];
	solve(n2, res, jump<<1);

	memset(sT, 0, N*3*sizeof(int));

	int nc = 1;
	rep(i, n2+1) {
		sT[i][1]=sT[i][2]=res[i];
		muls(sT[i][1], fact[i]);
		sT[n2-i][0] = mul(nc, factInv[i]);
		muls(nc, n2);
	}
	// cache optimizations, three simultaneous FFT
	ntt3(sT, N, jump);

	rep(i, N) {
		res[i] = sT[i][2];
		sTmp[i] = sT[i][0];
	}

	rep(i, N) muls(sTmp[i], sT[i][1]);
	ntti(sTmp, N, jump);
	rep(i, n2+1) {
		muls(sTmp[i+n2], factInv[i]);
		sTmp[i] = sTmp[i+n2];
	}
	memset(sTmp+n2+1, 0, (N-n2-1)*sizeof(int));
	ntt(sTmp, N, jump);
	rep(i, N) muls(res[i], sTmp[i]);
	ntti(res, N, jump);
	
	muls(tom, tom);
	muls(tom, mul(N, N));
}

int sn[1<<21];

int lastN = -1;
void initw(int n) {
	tom = 1;
	int N = 1 << loG2[n+1];
	if(lastN == N) return ;
	W[0] = W1[0] = 1;
	int w = pow_(g, (mod - 1) / N);
	for (int i = 1; i < N; ++i) {
		W[i] = mul(W[i-1], w);
	}
	w = inv_(w);
	for (int i = 1; i < N; ++i) {
		W1[i] = mul(W1[i-1], w);
	}
	ww = W;
	lastN = N;
}

main()
{
	init();
	int T;
	scan(T);
	vector<pair<pair<int, int>, int > > Q(T);
	rep(i, T) {
		scan2(Q[i].X.X, Q[i].X.Y);
		Q[i].Y = i;
	}
	vector<int> f_ans(T);
	sort(all(Q));
	
	rep(i, T) {
		int n = Q[i].X.X, k = Q[i].X.Y;

		initw(n);
		memset(sn, 0, 2*n*sizeof(int));
		solve(n, sn, 1); 

		tom = inv_(tom);
		rep(i, n) muls(sn[i], tom);
		
		int ans = 0;
		for (int i = 1; i <= k; ++i) {
			adds(ans, mul(sn[n-i], ncr(k-1, i-1)));
		}
		f_ans[Q[i].Y] = ans;
	}
	rep(i, T) pin(f_ans[i]);
	return 0;
}

